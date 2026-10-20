#include <globaldefs.h>
ARM

extern "C" void *Menu_FindSessionArenaById(void *tree, unsigned id);
extern "C" char *_ZN13SafeAllocator8AllocateEj(void *allocator, unsigned size);
extern "C" void SaveData_ResetTransferProgress(unsigned char *p);
// Original data: arm9/ov004 @ 0x2171034; symbol: data_ov004_02171034.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov004 @ 0x0216E210; symbol: func_ov004_0216e210; size: 0x48.
extern "C" int InitializeGlobalTreeEntry(void *tree) {
    void *node = Menu_FindSessionArenaById(tree, 6);
    if (node != 0) {
        char *allocation = _ZN13SafeAllocator8AllocateEj((char *)node + 4, 8);
        *(char **)(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage + 0x10) = allocation;
    }
    SaveData_ResetTransferProgress(*(unsigned char **)(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage + 0x10));
    InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[5] = 0;
    return 0;
}
