#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void InitializeFourWordsWithInvalidIndex(signed char*);
extern "C" void VectorizedMemset(void*,int,unsigned);
struct Flags {unsigned short value:14;unsigned short bit:1;unsigned short top:1;};
// Original: arm9/ov017 @ 0x021A967C; symbol: func_ov017_021a967c; size: 0x98.
extern "C" void Resource_InitializeType3ARecordAndAllocator(unsigned char* p,int value){
 InitializeFourWordsWithInvalidIndex((signed char*)p);
 p[0]=0x3a;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0xc);
 p[8]=0;*(int*)(p+0x20)=0;p[0x24]=value;p[9]=0;p[0x25]=0;p[0x26]=0;
 VectorizedMemset(p+0x28,0,6);
 memset(p+0x2e,0,11);
 ((Flags*)(p+0x3a))->value=0;
 p[0x39]=0;
 ((Flags*)(p+0x3a))->bit=0;
 VectorizedMemset(p+0x3c,0,24);
 *(int*)(p+0x54)=0;
}
