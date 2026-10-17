#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/ov017 @ 0x021B57FC; symbol: func_ov017_021b57fc; size: 0xBC.
extern "C" void Graphics_InitializeDisplayState21(char* self) {
InitializeFourWordsWithInvalidIndex((signed char*)self);
self[0]=21;
*(unsigned*)(self+8)=0;
self[12]=0;
*(unsigned short*)(self+16)=0xffff;
*(unsigned*)(self+28)=0;
*(unsigned short*)(self+14)=0;
*(unsigned*)(self+32)=0;
*(unsigned*)(self+36)=0;
*(int*)(self+40)=-1;
*(unsigned short*)(self+18)=0xffff;
self[22]=61;
*(unsigned*)(self+56)=0;
self[23]=0;
*(short*)(self+20)=-1;
*(unsigned short*)(self+24)=500;
_ZN13SafeAllocator21ResetAllocatorPointerEv(self+64);
_ZN13SafeAllocator21ResetAllocatorPointerEv(self+88);
void* buffer=*(void**)(ReadWordFieldAtOffset1C()+0x5c);
memset(*(void**)(self+60)=buffer,0,0x960);
unsigned selection=(*(volatile unsigned*)0x04000000&0x1f00)>>8;
unsigned display=*(volatile unsigned*)0x04000000;
*(volatile unsigned*)0x04000000=(display&~0x1f00)|((selection|16)<<8);
self[84]=0;
}
