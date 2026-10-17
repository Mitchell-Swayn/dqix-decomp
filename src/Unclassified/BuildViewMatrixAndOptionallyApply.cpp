#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 4
struct Vector {int x,y,z;};struct Matrix43 {int v[12];};
extern "C" void Mat4x3_WriteViewMatrix(const Vector*,const Vector*,const Vector*,Matrix43*);extern "C" void Geometry_LoadMatrix4x3ToCommandFIFO(Matrix43*);
// Original: arm9/main @ 0x020C57D4; symbol: func_020c57d4; size: 0x4C.
extern "C" void BuildViewMatrixAndOptionallyApply(const Vector* a,const Vector* b,const Vector* c,int apply,Matrix43* output){Matrix43 temp;if(!output)output=&temp;Mat4x3_WriteViewMatrix(a,b,c,output);if(!apply)return;{*(volatile unsigned*)0x04000440=2;Geometry_LoadMatrix4x3ToCommandFIFO(output);}}
