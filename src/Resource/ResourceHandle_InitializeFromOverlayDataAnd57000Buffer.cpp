#include <globaldefs.h>
// Original data: arm9/ov032 @ 0x2200180; symbol: data_ov032_02200180.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 110 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov032.md.
extern "C" char Bgm_LoadArchiveIntoLargeOverlayBuffer_PathDataSoundBgmSdat[],BgmLoadArchiveIntoLargeOverlayBuffer_UnknownRoleZeroInitializedStorage[];extern "C" void ResourceHandle_AllocateLoadAndReadValue(void*,void*,void*,unsigned,int);
// Original: arm9/main @ 0x0209C290; symbol: func_0209c290; size: 0x28.
extern "C" void ResourceHandle_InitializeFromOverlayDataAnd57000Buffer(void* self) {ResourceHandle_AllocateLoadAndReadValue(self,Bgm_LoadArchiveIntoLargeOverlayBuffer_PathDataSoundBgmSdat,BgmLoadArchiveIntoLargeOverlayBuffer_UnknownRoleZeroInitializedStorage,0x57000,1);}
