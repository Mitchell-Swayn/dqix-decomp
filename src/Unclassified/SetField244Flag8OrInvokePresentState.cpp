#include <globaldefs.h>
ARM
extern "C" int ReadWordFieldAtOffset218();extern "C" void func_020a212c(void*,int);
// Original: arm9/main @ 0x020A20F0; symbol: func_020a20f0; size: 0x3C.
extern "C" void SetField244Flag8OrInvokePresentState(unsigned char* p){if(ReadWordFieldAtOffset218()){p[0x244]|=8;return;}if(!*(int*)(p+0x238))return;func_020a212c(p,1);}
