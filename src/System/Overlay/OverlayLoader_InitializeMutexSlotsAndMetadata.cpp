#include <globaldefs.h>
// Original data: arm9/itcm @ 0x1ffd340; symbol: data_01ffd340.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/itcm.md.
// Original data: arm9/itcm @ 0x1ffd344; symbol: data_01ffd344.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/itcm.md.
// Original data: arm9/itcm @ 0x1ffd348; symbol: data_01ffd348.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/itcm.md.
// Original data: arm9/itcm @ 0x1ffd34c; symbol: data_01ffd34c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/itcm.md.
// Original data: arm9/itcm @ 0x1ffd364; symbol: data_01ffd364.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/itcm.md.
// Original data: arm9/itcm @ 0x1ffd394; symbol: data_01ffd394.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1540 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/itcm.md.
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void*);extern "C" void OverlayLoader_ClearSixSlotEntries(void*);extern "C" void _Z19LoadOverlayMetadataP15OverlayMetadatabj(void*,bool,unsigned);extern "C" char OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3[],IsSceneLoaded_UnknownRoleZeroInitializedStorage_Variant2[],OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant4[];extern "C" char OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2,OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage;extern "C" int IsSceneLoaded_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020A1838; symbol: func_020a1838; size: 0x9C.
extern "C" ARM void OverlayLoader_InitializeMutexSlotsAndMetadata(){_Z19ZeroInitializeMutexP5Mutex(OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3);OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2=1;OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage=0;for(unsigned i=0;i<8;++i)OverlayLoader_ClearSixSlotEntries(IsSceneLoaded_UnknownRoleZeroInitializedStorage_Variant2+6*i);for(unsigned i=0;i<35;++i)_Z19LoadOverlayMetadataP15OverlayMetadatabj(OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant4+44*i,false,i);IsSceneLoaded_UnknownRoleZeroInitializedStorage=0;}
