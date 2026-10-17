#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215C270; symbol: func_ov003_0215c270; size: 0x90.
extern "C" void Graphics_InitializeGeometryRegisters(unsigned unused,unsigned value,unsigned attribute) {
*(volatile unsigned*)0x040004a8=0x900000;
*(volatile unsigned*)0x040004a4=(attribute<<16)|0xc0;
*(volatile unsigned*)0x04000444=0;
volatile unsigned* command=(volatile unsigned*)0x0400046c;
*command=0x100000; *command=0xc0000; *command=0;
*(volatile unsigned*)0x04000500=1;
*(volatile unsigned*)0x04000480=value;
volatile unsigned* matrix=(volatile unsigned*)0x0400048c;
*matrix=0x10001000; *matrix=0;
*matrix=0x1000f000; *matrix=0;
*matrix=0xf000f000; *matrix=0;
*matrix=0xf0001000; *matrix=0;
*(volatile unsigned*)0x04000504=0;
*(volatile unsigned*)0x04000448=1;
}
