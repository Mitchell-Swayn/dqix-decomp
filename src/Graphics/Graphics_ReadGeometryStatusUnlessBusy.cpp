#pragma optimize_for_size off
#include <globaldefs.h>
// Original: arm9/main @ 0x020C56B0; symbol: func_020c56b0; size: 0x2C.
extern "C" int Graphics_ReadGeometryStatusUnlessBusy(unsigned* result) { if(*(volatile unsigned*)0x04000600 & 1) return -1; *result=*(volatile unsigned*)0x04000600 & 2; return 0; }
