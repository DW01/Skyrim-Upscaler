#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// tex                               texture  float4          2d             t0      1 
// edge                              texture  float4          2d             t1      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// TEXCOORD                 0   xy          1     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_TARGET                0   xyzw        0   TARGET   float   xyzw
//
ps_5_0
dcl_globalFlags refactoringAllowed
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_input_ps linear v1.xy
dcl_output o0.xyzw
dcl_temps 3
deriv_rtx_coarse r0.x, v1.x
deriv_rty_coarse r0.y, v1.y
resinfo_indexable(texture2d)(float,float,float,float) r0.zw, l(0), t0.zwxy
mul r0.xy, r0.xyxx, r0.zwzz
mul r0.zw, r0.zzzw, v1.xxxy
frc r1.xy, r0.zwzz
ge r1.zw, r1.xxxy, l(0.000000, 0.000000, 0.500000, 0.500000)
add r2.xy, -r1.xyxx, l(1.000000, 1.000000, 0.000000, 0.000000)
movc r1.xy, r1.zwzz, r2.xyxx, r1.xyxx
mad r0.xy, r0.xyxx, l(0.500000, 0.500000, 0.000000, 0.000000), r1.xyxx
dp2 r1.x, r1.xyxx, l(1.000000, 1.000000, 0.000000, 0.000000)
lt r1.x, r1.x, l(0.500000)
dp2 r0.x, r0.xyxx, l(1.000000, 1.000000, 0.000000, 0.000000)
lt r0.x, r0.x, l(0.500000)
movc r0.x, r0.x, l(1.000000), l(0.500000)
movc r0.x, r1.x, r0.x, l(0.500000)
add r0.y, -r0.x, l(1.000000)
ftoi r1.xy, r0.zwzz
add r0.zw, r0.zzzw, r0.zzzw
ftoi r2.xy, r0.zwzz
mov r1.zw, l(0,0,0,0)
ld_indexable(texture2d)(float,float,float,float) r1.xyzw, r1.xyzw, t0.xyzw
mul r1.xyzw, r0.yyyy, r1.xyzw
mov r2.zw, l(0,0,0,0)
ld_indexable(texture2d)(float,float,float,float) r2.xyzw, r2.xyzw, t1.xyzw
mad o0.xyzw, r0.xxxx, r2.xyzw, r1.xyzw
ret 
// Approximately 27 instruction slots used
#endif

const BYTE xbr_ps[] =
{
     68,  88,  66,  67, 156, 170, 
     57,  93, 155, 115, 141, 189, 
     21, 185, 232, 244, 204, 181, 
    246, 232,   1,   0,   0,   0, 
    168,   5,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    236,   0,   0,   0,  68,   1, 
      0,   0, 120,   1,   0,   0, 
     12,   5,   0,   0,  82,  68, 
     69,  70, 176,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
    255, 255,   0,   1,   0,   0, 
    133,   0,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    124,   0,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 128,   0,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0, 116, 101, 
    120,   0, 101, 100, 103, 101, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     49,  48,  46,  49,   0, 171, 
    171, 171,  73,  83,  71,  78, 
     80,   0,   0,   0,   2,   0, 
      0,   0,   8,   0,   0,   0, 
     56,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     68,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   3,   3,   0,   0, 
     83,  86,  95,  80,  79,  83, 
     73,  84,  73,  79,  78,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0, 171, 171, 171, 
     79,  83,  71,  78,  44,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  83,  86, 
     95,  84,  65,  82,  71,  69, 
     84,   0, 171, 171,  83,  72, 
     69,  88, 140,   3,   0,   0, 
     80,   0,   0,   0, 227,   0, 
      0,   0, 106,   8,   0,   1, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      1,   0,   0,   0,  85,  85, 
      0,   0,  98,  16,   0,   3, 
     50,  16,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   0,   0, 
      0,   0, 104,   0,   0,   2, 
      3,   0,   0,   0, 122,   0, 
      0,   5,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,  16, 
     16,   0,   1,   0,   0,   0, 
    124,   0,   0,   5,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26,  16,  16,   0,   1,   0, 
      0,   0,  61,   0,   0, 137, 
    194,   0,   0, 128,  67,  85, 
     21,   0, 194,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
    230, 116,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0, 230,  10, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7, 194,   0, 
     16,   0,   0,   0,   0,   0, 
    166,  14,  16,   0,   0,   0, 
      0,   0,   6,  20,  16,   0, 
      1,   0,   0,   0,  26,   0, 
      0,   5,  50,   0,  16,   0, 
      1,   0,   0,   0, 230,  10, 
     16,   0,   0,   0,   0,   0, 
     29,   0,   0,  10, 194,   0, 
     16,   0,   1,   0,   0,   0, 
      6,   4,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,  63, 
      0,   0,   0,  63,   0,   0, 
      0,  11,  50,   0,  16,   0, 
      2,   0,   0,   0,  70,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     55,   0,   0,   9,  50,   0, 
     16,   0,   1,   0,   0,   0, 
    230,  10,  16,   0,   1,   0, 
      0,   0,  70,   0,  16,   0, 
      2,   0,   0,   0,  70,   0, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  12,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  63,   0,   0, 
      0,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,  70,   0, 
     16,   0,   1,   0,   0,   0, 
     15,   0,   0,  10,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   0,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,  49,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,  63,  15,   0,   0,  10, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     49,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  63,  55,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,   1,  64,   0,   0, 
      0,   0,   0,  63,  55,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  63,   0,   0, 
      0,   8,  34,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     27,   0,   0,   5,  50,   0, 
     16,   0,   1,   0,   0,   0, 
    230,  10,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   7, 
    194,   0,  16,   0,   0,   0, 
      0,   0, 166,  14,  16,   0, 
      0,   0,   0,   0, 166,  14, 
     16,   0,   0,   0,   0,   0, 
     27,   0,   0,   5,  50,   0, 
     16,   0,   2,   0,   0,   0, 
    230,  10,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   8, 
    194,   0,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  45,   0, 
      0, 137, 194,   0,   0, 128, 
     67,  85,  21,   0, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 242,   0,  16,   0, 
      1,   0,   0,   0,  86,   5, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  54,   0,   0,   8, 
    194,   0,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  45,   0, 
      0, 137, 194,   0,   0, 128, 
     67,  85,  21,   0, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70, 126,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,   9, 242,  32,  16,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    148,   0,   0,   0,  27,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0
};