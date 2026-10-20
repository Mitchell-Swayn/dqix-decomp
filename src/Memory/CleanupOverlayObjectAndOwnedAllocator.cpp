#include <globaldefs.h>
ARM
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];extern "C" void Graphics_FinalizeDisplayStateAndRestoreControls(unsigned);extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int);extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable();
// Original: arm9/main @ 0x020DAE08; symbol: func_020dae08; size: 0x60.
extern "C" void CleanupOverlayObjectAndOwnedAllocator(unsigned char* object){if(*(unsigned*)(object+12)){Graphics_FinalizeDisplayStateAndRestoreControls(*(unsigned*)(object+12));*(unsigned*)(object+12)=0;OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);}SignedAllocatorHeader* allocator=((SafeAllocator*)(object+20))->GetSignedAllocator();if(allocator){((SafeAllocator*)(object+20))->Destroy();Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocator);}FileCache_RestoreRomTablesIfSpaceAvailable();object[1]=1;}
