#include <globaldefs.h>
THUMB
// Original: arm9/main @ 0x020C1264; symbol: Mat3x3_WriteRotationX; size: 0x1C.
extern "C" void MTX_RotX33_(int* p,int sine,int cosine) { p[0]=0x1000;p[1]=0;p[2]=0;p[3]=0;p[4]=cosine;p[5]=sine;p[6]=0;p[7]=-sine;p[8]=cosine; }
