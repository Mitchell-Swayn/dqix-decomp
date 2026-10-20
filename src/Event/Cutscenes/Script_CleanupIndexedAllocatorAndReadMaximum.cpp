#include <globaldefs.h>
struct IntegerParameterView;
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" char* EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
extern "C" unsigned Memory_ReadMaximumAlignedAllocation(char*);
// Original: arm9/ov001 @ 0x0215EA40; symbol: func_ov001_0215ea40; size: 0x70.
extern "C" int Script_CleanupIndexedAllocatorAndReadMaximum(IntegerParameterView* parameter) {
    int index = Script_ReadParameterAsInteger(parameter);
    if (index < 0 || index >= 8) return 0;
    void* allocator = EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[index];
    if (allocator == 0) return 0;
    void* allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocator);
    if (allocation != 0) {
        _ZN13SafeAllocator7DestroyEv(allocator);
        Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
    }
    Memory_ReadMaximumAlignedAllocation((char*)Main_UnknownRoleZeroInitializedStorage_Variant3);
    return 1;
}
