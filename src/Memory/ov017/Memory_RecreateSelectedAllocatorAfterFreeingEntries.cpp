#include <globaldefs.h>
ARM
struct AllocatorUnion;
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void InitializeStateFieldsAndFourEntries(char*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" char data_02114e20[];
extern "C" int data_ov017_021d669c[];
// Original: arm9/ov017 @ 0x021A050C; symbol: func_ov017_021a050c; size: 0x9C.
extern "C" void Memory_RecreateSelectedAllocatorAfterFreeingEntries(unsigned char* p){
 InitializeStateFieldsAndFourEntries(*(char**)(p+0x36d0));

 for(int i=0;data_ov017_021d669c[i]>=0;i++){
 int offset=data_ov017_021d669c[i]*20;
 void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x38+offset);
 _ZN13SafeAllocator7DestroyEv(p+0x38+offset);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x38+offset);
 if(allocation)Memory_FreeThroughAllocatorUnion(data_02114e20,allocation);
 }
 void* memory=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)data_02114e20,0x6f78);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x9c,memory,0x6f78);
}
