#include <globaldefs.h>
ARM
extern "C" void Inn_ReleaseServiceMenuGraphics(void*);
extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void Graphics_ApplyMainBackgroundSnapshotAndClearPending(void*);
extern "C" unsigned GetMainBGAssignedVRAMSize();
extern "C" void MIi_CpuClearFast(int,void*,unsigned);
extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable();
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3;
// Original: arm9/ov003 @ 0x0217F118; symbol: Graphics_ReleaseSelectionResourcesAndClearMainBG; size: 0x7c.
// Releases nested resources and allocator, clears main BG VRAM, and marks completion.
extern "C" void Graphics_ReleaseSelectionResourcesAndClearMainBG(char* self) {
 if (*(void**)(self+12)) {Inn_ReleaseServiceMenuGraphics(*(void**)(self+12)); *(void**)(self+12)=0; OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);}
 void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(self+20);
 if(allocation) {_ZN13SafeAllocator7DestroyEv(self+20); Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);}
 Graphics_ApplyMainBackgroundSnapshotAndClearPending(self+42);
 MIi_CpuClearFast(0,(void*)0x6000000,GetMainBGAssignedVRAMSize());
 FileCache_RestoreRomTablesIfSpaceAvailable(); self[1]=1;
}
