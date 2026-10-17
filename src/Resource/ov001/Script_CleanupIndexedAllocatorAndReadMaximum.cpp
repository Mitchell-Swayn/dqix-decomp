#include <globaldefs.h>
struct IntegerParameterView;
extern "C" char* data_ov001_021658b8[];
extern "C" unsigned char data_02114e20[];
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
extern "C" unsigned Memory_ReadMaximumAlignedAllocation(char*);
// Original: arm9/ov001 @ 0x0215EA40; symbol: func_ov001_0215ea40; size: 0x70.
extern "C" int Script_CleanupIndexedAllocatorAndReadMaximum(IntegerParameterView* parameter) {
    int index = ReadScriptParameterAsInteger(parameter);
    if (index < 0 || index >= 8) return 0;
    void* allocator = data_ov001_021658b8[index];
    if (allocator == 0) return 0;
    void* allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocator);
    if (allocation != 0) {
        _ZN13SafeAllocator7DestroyEv(allocator);
        Memory_FreeThroughAllocatorUnion(data_02114e20, allocation);
    }
    Memory_ReadMaximumAlignedAllocation((char*)data_02114e20);
    return 1;
}
