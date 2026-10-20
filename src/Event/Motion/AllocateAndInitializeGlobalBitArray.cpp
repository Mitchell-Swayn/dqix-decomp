#include <globaldefs.h>
ARM
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned int, unsigned int);
extern "C" void SaveData_ResetTransferProgress(unsigned char *);
extern "C" void *GameState_GetSerializedProgressState();
extern "C" void BitArray_SetIndexedBoolean(void *, unsigned char *, int, int);
extern "C" void *memset(void *, int, unsigned int);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov001 @ 0x02163008; symbol: AllocateAndInitializeGlobalBitArray; size: 0x68.
// Allocates and clears an 8-byte block and 0x8000-byte bit array, stores them in global slots, then sets bit 0x1142.
extern "C" int AllocateAndInitializeGlobalBitArray(void) {
    void *allocator = *(void **)EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;
    unsigned char *small = (unsigned char *)_ZN13SafeAllocator8AllocateEj((unsigned int)allocator, 8);
    *(void **)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0x4b4) = small;
    SaveData_ResetTransferProgress(small);
    unsigned char *bits = (unsigned char *)_ZN13SafeAllocator8AllocateEj((unsigned int)allocator, 0x8000);
    *(void **)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0x4b8) = bits;
    memset(bits, 0, 0x8000);
    void *global = GameState_GetSerializedProgressState();
    BitArray_SetIndexedBoolean(global, (unsigned char *)global + 0x8c, 0x1142, 1);
    return 1;
}
