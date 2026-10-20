#include <globaldefs.h>
ARM
extern "C" void MI_Copy36B(volatile void*,void*,volatile void*);
// Original: arm9/main @ 0x020C552C; symbol: func_020c552c; size: 0x30.
extern "C" int Graphics_ReadMatrixWhenGeometryNotBusy(void* p){volatile unsigned* regs=(volatile unsigned*)0x04000600;if(*regs&0x08000000)return -1;MI_Copy36B(regs+32,p,regs);return 0;}
