#include <globaldefs.h>
#pragma optimization_level 2
#pragma optimize_for_size off
// Original: arm9/main @ 0x020C5650; symbol: func_020c5650; size: 0x30.
extern "C" ARM int Geometry_ReadPositionMatrixStackLevel(unsigned* out){volatile unsigned* status=(volatile unsigned*)0x04000600;if(*status&0x4000)return -1;*out=(*status&0x1f00)>>8;return 0;}
