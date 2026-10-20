#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 4
struct Matrix44 {int v[16];};
extern "C" void Mat4x4_WriteProjectionUnknown(int,int,int,int,int,int,int,Matrix44*);extern "C" void Graphics_WriteGeometryCommand22AndValue(Matrix44*);
// Original: arm9/main @ 0x020C5770; symbol: func_020c5770; size: 0x64.
extern "C" void Geometry_BuildAndOptionallyApplyProjectionMatrix(int a,int b,int c,int d,int e,int f,int g,int apply,Matrix44* output){Matrix44 temp;if(!output)output=&temp;Mat4x4_WriteProjectionUnknown(a,b,c,d,e,f,g,output);if(!apply)return;{*(volatile unsigned*)0x04000440=0;Graphics_WriteGeometryCommand22AndValue(output);}}
