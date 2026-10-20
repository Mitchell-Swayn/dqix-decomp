#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
extern "C" void _ZN13HMRFAllocator4FreeEi(void *allocator, int freeFlag);
// Original: arm9/ov001 @ 0x02161900; symbol: func_ov001_02161900; size: 0x30.
extern "C" int Resource_FreeIndexedHMRFRecord(IntegerParameterView *parameter) {
    int index = Script_ReadParameterAsInteger(parameter);
    void *record = *(void **)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + index * 4);
    if (record)
        _ZN13HMRFAllocator4FreeEi(*(void **)record, 1);
    return 1;
}
