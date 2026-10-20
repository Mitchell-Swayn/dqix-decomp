#include <globaldefs.h>
ARM
extern "C" void* Menu_FindSessionArenaById(void*, unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void PopulateOwnerThresholdSlotsAndResourceText(void*, int);
// Original data: arm9/ov004 @ 0x2171024; symbol: data_ov004_02171024.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x02167D04; symbol: func_ov004_02167d04; size: 0x6C.
extern "C" int Script_InitializeLookupBuffers(void* owner) {
    void* allocator = Menu_FindSessionArenaById(owner, 0);
    if (allocator) {
        ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[1] = (unsigned)_ZN13SafeAllocator8AllocateEj((unsigned)allocator + 4, 0xc);
        ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[0] = (unsigned)_ZN13SafeAllocator8AllocateEj((unsigned)allocator + 4, 0x80);
        ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[2] = (unsigned)_ZN13SafeAllocator8AllocateEj((unsigned)allocator + 4, 0x80);
        PopulateOwnerThresholdSlotsAndResourceText(owner, 0);
    }
    return 0;
}
