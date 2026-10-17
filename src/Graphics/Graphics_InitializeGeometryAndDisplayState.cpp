#include "globaldefs.h"
#pragma optimize_for_size off
ARM
extern "C" void Graphics_ResetGeometryMatrixStackState();
// Original: arm9/main @ 0x020C52E8; symbol: func_020c52e8; size: 0x6C.
extern "C" void Graphics_InitializeGeometryAndDisplayState(){volatile unsigned*status=(volatile unsigned*)0x04000600;while(*status&0x08000000){}*status|=0x8000;volatile unsigned short*display=(volatile unsigned short*)0x04000060;*display|=0x2000;*display|=0x1000;Graphics_ResetGeometryMatrixStackState();volatile unsigned*result=(volatile unsigned*)0x040004a4;result[0]=0x1f0080;result[1]=0;result[2]=0;}
