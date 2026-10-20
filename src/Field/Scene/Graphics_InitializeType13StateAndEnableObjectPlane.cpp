#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
// Original: arm9/ov017 @ 0x021BF410; symbol: func_ov017_021bf410; size: 0x80.
extern "C" void Graphics_InitializeType13StateAndEnableObjectPlane(char* p) {
 LinkedQueue_InitializeNodeStatus((signed char*)p);
 p[0]=13; p[0xa]=0; p[0xb]=0;
 *(int*)(p+0xc)=0; *(int*)(p+0x10)=0;
 *(short*)(p+0x14)=-1; *(short*)(p+0x16)=61; *(short*)(p+0x18)=0; *(short*)(p+8)=0;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x34);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x4c);
 volatile unsigned int* display=(volatile unsigned int*)0x04000000;
 unsigned int planes=(*display & 0x1f00)>>8;
 *display=(*display & ~0x1f00)|((planes|0x10)<<8);
 p[0x48]=0;
}
