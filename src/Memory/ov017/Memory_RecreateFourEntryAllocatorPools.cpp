#include <globaldefs.h>
ARM
struct Reset;struct AllocatorUnion;
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" void* ReadGlobalAt020FDD44();
extern "C" char* GetBoundedEntryAtStride318(void*,int);
extern "C" void Object_ResetFlagsAndEmbeddedRecordState(Reset*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" char data_02114e20[];
// Original: arm9/ov017 @ 0x0219FEC0; symbol: func_ov017_0219fec0; size: 0x98.
extern "C" void Memory_RecreateFourEntryAllocatorPools() {
ReadGlobalValueAt020FB3F0();
void* state=ReadGlobalAt020FDD44();
char* entry=GetBoundedEntryAtStride318(state,0);
Object_ResetFlagsAndEmbeddedRecordState((Reset*)entry);
void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(*(void**)(entry+0x10));
if(allocation) {
_ZN13SafeAllocator7DestroyEv(*(void**)(entry+0x10));
Memory_FreeThroughAllocatorUnion(data_02114e20,allocation);
}
for(int i=0;i<4;++i) {
char* e=GetBoundedEntryAtStride318(state,i);
void* p=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)data_02114e20,0x28a0);
_ZN13SafeAllocator11CreateTypeAEPvj(*(void**)(e+0x10),p,0x28a0);
}
}
