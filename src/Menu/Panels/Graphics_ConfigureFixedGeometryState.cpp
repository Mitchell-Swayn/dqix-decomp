#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021DACD4; symbol: func_ov023_021dacd4; size: 0xA4.
extern "C" void Graphics_ConfigureFixedGeometryState(unsigned unused,unsigned color,unsigned attr){
volatile unsigned* reg=(volatile unsigned*)0x040004a8;
(*(volatile unsigned*)0x040004a8)=0x900000;(*(volatile unsigned*)0x040004a4)=(attr<<16)|0xc0;
(*(volatile unsigned*)0x04000444)=0;
(*(volatile unsigned*)0x04000470)=0;(*(volatile unsigned*)0x04000470)=0;(*(volatile unsigned*)0x04000470)=0xfff80000;
(*(volatile unsigned*)0x0400046c)=0x100000;(*(volatile unsigned*)0x0400046c)=0xc0000;(*(volatile unsigned*)0x0400046c)=0;
(*(volatile unsigned*)0x04000500)=1;(*(volatile unsigned*)0x04000480)=color;
(*(volatile unsigned*)0x0400048c)=0x10001000;(*(volatile unsigned*)0x0400048c)=0;(*(volatile unsigned*)0x0400048c)=0x1000f000;(*(volatile unsigned*)0x0400048c)=0;
(*(volatile unsigned*)0x0400048c)=0xf000f000;(*(volatile unsigned*)0x0400048c)=0;(*(volatile unsigned*)0x0400048c)=0xf0001000;(*(volatile unsigned*)0x0400048c)=0;
(*(volatile unsigned*)0x04000504)=0;(*(volatile unsigned*)0x04000448)=1;
}
