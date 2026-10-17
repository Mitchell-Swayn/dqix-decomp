#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void Memory_DestroyFourteenEmbeddedAllocators(char*);
extern "C" char data_02114e20[];
extern "C" int data_ov017_021d68cc[];
// Original: arm9/ov017 @ 0x021A0470; symbol: func_ov017_021a0470; size: 0x9C.
extern "C" void Memory_DestroyEmbeddedAndIndexedAllocators(char* self) {
for(int i=0;i<4;++i)Memory_DestroyFourteenEmbeddedAllocators(self+0x12c8+i*0x5ec);
int i=0;
for(;data_ov017_021d68cc[i]>=0;++i){
unsigned int index=data_ov017_021d68cc[i];
void* allocation=((SafeAllocator*)(self+0x38))[index].GetSignedAllocator();
((SafeAllocator*)(self+0x38))[index].Destroy();
((SafeAllocator*)(self+0x38))[index].ResetAllocatorPointer();
if(allocation)Memory_FreeThroughAllocatorUnion(data_02114e20,allocation);
}
}
