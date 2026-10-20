#include <globaldefs.h>
#pragma optimization_level 2
#include <System/Mutex.h>
#include <Resource/ResourceMutex.h>

// Original data: arm9/itcm @ 0x1ffd348; symbol: data_01ffd348.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/itcm.md.
extern "C" volatile unsigned IsSceneLoaded_UnknownRoleZeroInitializedStorage;
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
extern "C" volatile unsigned char OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2, OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage;
// Original data: arm9/itcm @ 0x1ffd34c; symbol: data_01ffd34c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/itcm.md.
extern "C" Mutex OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3;
// Original data: arm9/itcm @ 0x1ffd364; symbol: data_01ffd364.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/itcm.md.
extern "C" unsigned char IsSceneLoaded_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/itcm @ 0x1ffd394; symbol: data_01ffd394.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1540 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/itcm.md.
extern "C" char OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant4[];
struct Entry { unsigned offset, unknown; };
// Original data: arm9/main @ 0x20e8f20; symbol: data_020e8f20.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 0000000069190f020000000050190f02000000008e190f0200000000c8190f02000000006e1a0f0200000000021a0f020000000070190f02010000004a190f02 ...; full span in module reference.
// Observed span: 280 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Entry IsSceneLoaded_UnknownRoleDataReferences[];
extern "C" void ProcessorContext_SleepOrYieldPriorityPeers(int);
extern "C" void OverlayLoader_RunRegionCleanupAndReturnSuccess(void*);

// Original: arm9/main @ 0x020A1CCC; symbol: func_020a1ccc; size: 0x118.
extern "C" ARM int OverlayLoader_CleanupOverlayForVmRead(unsigned index)
{
    int result = 0;
    if (index < 35) {
        volatile Entry* table = IsSceneLoaded_UnknownRoleDataReferences;
        unsigned slot = IsSceneLoaded_UnknownRoleZeroInitializedStorage;
        if (OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2) LockMutex(&OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3);
        // Shared status bytes must be stored before the following flag read.
        volatile signed char* buffer = (signed char*)IsSceneLoaded_UnknownRoleZeroInitializedStorage_Variant2 + slot * 6;
        buffer[table[index].offset] = index | 64;
        if (OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2) UnlockMutex(&OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3);
        while (OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage) ProcessorContext_SleepOrYieldPriorityPeers(0);
        OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage = 1;
        LockResourceMutex();
        OverlayLoader_RunRegionCleanupAndReturnSuccess(OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant4 + index * 44);
        UnlockResourceMutex();
        OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage = 0;
        if (OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2) LockMutex(&OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3);
        buffer[table[index].offset] = -1;
        if (OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant2) UnlockMutex(&OverlayLoaderLoadOverlay_UnknownRoleZeroInitializedStorage_Variant3);
        result = 1;
    }
    return result;
}
