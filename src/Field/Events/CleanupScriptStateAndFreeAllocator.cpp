#include <globaldefs.h>
ARM
extern "C" void * _ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable(void);
extern "C" void *Script_ReadGlobalExecutionValue(void);
extern "C" void TimedMessageQueue_CancelAndClear(void *);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3;
// Original: arm9/ov017 @ 0x021A55B0; symbol: CleanupScriptStateAndFreeAllocator; size: 0x50.
// Destroys/frees the active allocator when present, cleans the script owner state, resets the allocator pointer, and clears state word +8.
extern "C" void CleanupScriptStateAndFreeAllocator(void *state) {
 void *allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char *)state + 0xc);
 if (allocator) {
  _ZN13SafeAllocator7DestroyEv((char *)state + 0xc);
  Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3, allocator);
  FileCache_RestoreRomTablesIfSpaceAvailable();
 }
 void *owner = Script_ReadGlobalExecutionValue();
 TimedMessageQueue_CancelAndClear(owner);
 _ZN13SafeAllocator21ResetAllocatorPointerEv((char *)state + 0xc);
 *(unsigned int *)((char *)state + 8) = 0;
}
