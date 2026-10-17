#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void InitializeRecordBuffersAndEnabledByte(unsigned char*);
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" void ClearRecordAndInvalidateTwoIndices(char*);
// Original: arm9/ov003 @ 0x0217DAF0; symbol: func_ov003_0217daf0; size: 0x98.
extern "C" void Graphics_InitializeDisplayStateAndRecordAllocators(unsigned char* p){
 *(unsigned*)p=(*(volatile unsigned*)0x04000000&0x1f00)>>8;
 p[4]=0;p[5]=0;p[6]=0;
 *(unsigned short*)(p+8)=1;
 *(int*)(p+0xc)=0;*(int*)(p+0x14)=0;
 p[0x30]=0;p[0x31]=0;
 VectorizedMemset(p+0x18,0,0x18);
 *(int*)(p+0x34)=0;*(int*)(p+0x38)=0;
 InitializeRecordBuffersAndEnabledByte(p+0x3c);
 *(int*)(p+0x90)=0;*(int*)(p+0x94)=0;*(int*)(p+0x98)=0;*(int*)(p+0x9c)=0;*(int*)(p+0xa0)=0;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0xa4);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0xb8);
 ClearRecordAndInvalidateTwoIndices((char*)p+0xcc);
}
