#include <globaldefs.h>
ARM
extern "C" { void InitializeFourWordsWithInvalidIndex(signed char*); void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*); }
// Original: arm9/ov017 @ 0x021AA50C; symbol: func_ov017_021aa50c; size: 0x90.
extern "C" void Graphics_InitializeDisplayStateRecord(unsigned char* p) {
 InitializeFourWordsWithInvalidIndex((signed char*)p);
 p[0]=0x1a;
 *(unsigned*)(p+12)=(*(volatile unsigned*)0x04000000&0x1f00)>>8;
 *(int*)(p+8)=0;
 *(int*)(p+24)=0;
 *(int*)(p+32)=0;
 *(int*)(p+28)=0;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+36);
 *(int*)(p+56)=0; *(int*)(p+60)=0; *(int*)(p+64)=0; *(int*)(p+68)=0;
 *(short*)(p+72)=-1; *(short*)(p+74)=-1; *(short*)(p+76)=-11;
 *(int*)(p+80)=-1;
 *(int*)(p+16)=0; *(int*)(p+20)=0; *(int*)(p+84)=0; *(int*)(p+88)=0;
 p[92]=0; *(int*)(p+96)=0; *(int*)(p+100)=0;
}
