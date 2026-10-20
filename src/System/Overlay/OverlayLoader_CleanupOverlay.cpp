#pragma opt_lifetimes off
#pragma optimize_for_size off
#pragma opt_propagation off
#include <globaldefs.h>
ARM
typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
extern "C" void _Z9LockMutexP5Mutex(void*); extern "C" void _Z11UnlockMutexP5Mutex(void*); extern "C" void _Z17LockResourceMutexv(); extern "C" void _Z19UnlockResourceMutexv(); extern "C" void ProcessorContext_SleepOrYieldPriorityPeers(u32); extern "C" void OverlayLoader_RunRegionCleanupAndReturnSuccess(void *);
// Original data: arm9/main @ 0x20e8f20; symbol: data_020e8f20.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 0000000069190f020000000050190f02000000008e190f0200000000c8190f02000000006e1a0f0200000000021a0f020000000070190f02010000004a190f02 ...; full span in module reference.
// Observed span: 280 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
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
extern "C" volatile u32 IsSceneLoaded_UnknownRoleZeroInitializedStorage; extern "C" volatile u8 OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2; extern "C" u8 IsSceneLoaded_UnknownRoleDataReferences[]; extern "C" u8 OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3[]; extern "C" u8 IsSceneLoaded_UnknownRoleZeroInitializedStorage_Variant2[]; extern "C" volatile u8 OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage; extern "C" u8 OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant4[];
// Original: arm9/main @ 0x020A1BB4; symbol: func_020a1bb4; size: 0x118.
extern "C" int OverlayLoader_CleanupOverlay(u32 id) {
 int result=0; if(id>=35) return result;
 u8 *map=IsSceneLoaded_UnknownRoleDataReferences; u32 slot=IsSceneLoaded_UnknownRoleZeroInitializedStorage;
 if(OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2) _Z9LockMutexP5Mutex(OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3);
 volatile signed char *entry=(volatile signed char*)IsSceneLoaded_UnknownRoleZeroInitializedStorage_Variant2+slot*6; entry[*(u32*)(map+id*8)]=id|0x40;
 if(OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2) _Z11UnlockMutexP5Mutex(OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3);
 u32 zero=0; slot=(u32)&OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage; while(*(u8*)slot) ProcessorContext_SleepOrYieldPriorityPeers(zero);
 OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage=1; _Z17LockResourceMutexv(); OverlayLoader_RunRegionCleanupAndReturnSuccess(OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant4+id*44); _Z19UnlockResourceMutexv(); OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage=0;
 if(OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2) _Z9LockMutexP5Mutex(OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3);
 entry[*(u32*)(map+id*8)]=-1;
 if(OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2) _Z11UnlockMutexP5Mutex(OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3);
 return 1;
}
