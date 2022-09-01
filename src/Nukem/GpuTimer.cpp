#include "GpuTimer.h"

GPUTimer g_GPUTimers;

void GPUTimer::Create(ID3D11Device *D3DDevice, uint32_t NumTimers)
{
	m_InFrame = false;
	m_DisjointQueryInFlight = false;
	m_Timers.resize(NumTimers);

	D3D11_QUERY_DESC queryDesc;
	memset(&queryDesc, 0, sizeof(D3D11_QUERY_DESC));
	queryDesc.Query = D3D11_QUERY_TIMESTAMP_DISJOINT;

	D3DDevice->CreateQuery(&queryDesc, &m_DisjointTimestampQuery);

	for (GPUTimerState& timer : m_Timers)
	{
		memset(&queryDesc, 0, sizeof(D3D11_QUERY_DESC));
		queryDesc.Query = D3D11_QUERY_TIMESTAMP;

		D3DDevice->CreateQuery(&queryDesc, &timer.GPUTimerBegin);
		D3DDevice->CreateQuery(&queryDesc, &timer.GPUTimerEnd);

		timer.TimestampQueryInFlight = false;
	}
}

void GPUTimer::Release()
{
	m_DisjointTimestampQuery->Release();
	m_DisjointTimestampQuery = nullptr;

	for (GPUTimerState& timer : m_Timers)
	{
		timer.GPUTimerBegin->Release();
		timer.GPUTimerEnd->Release();
	}

	m_Timers.clear();
}

void GPUTimer::BeginFrame(ID3D11DeviceContext *DeviceContext)
{
	m_InFrame = true;

	if (!m_DisjointQueryInFlight)
		DeviceContext->Begin(m_DisjointTimestampQuery);
}

void GPUTimer::EndFrame(ID3D11DeviceContext *DeviceContext)
{
	if (!m_DisjointQueryInFlight)
		DeviceContext->End(m_DisjointTimestampQuery);

	m_DisjointQueryInFlight = true;

	D3D11_QUERY_DATA_TIMESTAMP_DISJOINT disjointTimestampValue;
	UINT64 timestampValueBegin;
	UINT64 timestampValueEnd;

	if (DeviceContext->GetData(m_DisjointTimestampQuery, &disjointTimestampValue, sizeof(disjointTimestampValue), D3D11_ASYNC_GETDATA_DONOTFLUSH) == S_OK)
	{
		m_DisjointQueryInFlight = false;

		if (!disjointTimestampValue.Disjoint)
		{
			double invFrequencyMS = 1000.0 / disjointTimestampValue.Frequency;

			for (GPUTimerState& timer : m_Timers)
			{
				timer.GPUTimeInMS = 0.0f;

				if (timer.TimestampQueryInFlight &&
					DeviceContext->GetData(timer.GPUTimerBegin, &timestampValueBegin, sizeof(UINT64), D3D11_ASYNC_GETDATA_DONOTFLUSH) == S_OK &&
					DeviceContext->GetData(timer.GPUTimerEnd, &timestampValueEnd, sizeof(UINT64), D3D11_ASYNC_GETDATA_DONOTFLUSH) == S_OK)
				{
					timer.TimestampQueryInFlight = false;
					timer.GPUTimeInMS = float(double(timestampValueEnd - timestampValueBegin) * invFrequencyMS);
				}
			}
		}
	}

	m_InFrame = false;
}

void GPUTimer::StartTimer(ID3D11DeviceContext *DeviceContext, uint32_t Id)
{
	m_Timers[Id].Started = true;

	if (!m_Timers[Id].TimestampQueryInFlight)
		DeviceContext->End(m_Timers[Id].GPUTimerBegin);
}

void GPUTimer::StopTimer(ID3D11DeviceContext *DeviceContext, uint32_t Id)
{
	if (!m_Timers[Id].TimestampQueryInFlight)
		DeviceContext->End(m_Timers[Id].GPUTimerEnd);

	m_Timers[Id].TimestampQueryInFlight = true;
	m_Timers[Id].Started = false;
}

float GPUTimer::GetGPUTimeInMS(uint32_t Id)
{
	return m_Timers.at(Id).GPUTimeInMS;
}
