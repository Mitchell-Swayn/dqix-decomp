#include <globaldefs.h>
ARM
extern "C" void MI_Copy64B(volatile void*,void*,volatile void*);
// Original: arm9/main @ 0x020C54FC; symbol: func_020c54fc; size: 0x30.
extern "C" int Geometry_ReadClipMatrixWhenIdle(void* p){volatile unsigned* regs=(volatile unsigned*)0x04000600;if(*regs&0x08000000)return -1;MI_Copy64B(regs+16,p,regs);return 0;}
