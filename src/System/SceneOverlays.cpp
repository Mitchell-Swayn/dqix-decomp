#include <globaldefs.h>
#include "System/SceneOverlays.h"

#if defined(jpn)
#define IsSceneLoaded_UnknownRoleZeroInitializedStorage data_01ffd368
#define IsSceneLoaded_UnknownRoleZeroInitializedStorage_Variant2 data_01ffd384

#define IsSceneLoaded_UnknownRoleDataReferences data_020e9034
#endif

// Original data: arm9/main @ 0x20e8f20; symbol: data_020e8f20.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 0000000069190f020000000050190f02000000008e190f0200000000c8190f02000000006e1a0f0200000000021a0f020000000070190f02010000004a190f02 ...; full span in module reference.
// Observed span: 280 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const SceneEntry IsSceneLoaded_UnknownRoleDataReferences[];

// Original data: arm9/itcm @ 0x1ffd348; symbol: data_01ffd348.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/itcm.md.
extern int IsSceneLoaded_UnknownRoleZeroInitializedStorage;            // current slot bank
// Original data: arm9/itcm @ 0x1ffd364; symbol: data_01ffd364.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/itcm.md.
extern signed char IsSceneLoaded_UnknownRoleZeroInitializedStorage_Variant2[];  // six slots per bank, 8 banks?

// usa: func_020a18f4
// Original: arm9/main @ 0x020A18F4; symbol: _Z13IsSceneLoadedj; size: 0x4C.
ARM bool IsSceneLoaded(unsigned int scene)
{
    bool loaded = false;

    if (scene < SCENE_COUNT)
    {
        const signed char* slots = &IsSceneLoaded_UnknownRoleZeroInitializedStorage_Variant2[IsSceneLoaded_UnknownRoleZeroInitializedStorage * 6];
        loaded = slots[IsSceneLoaded_UnknownRoleDataReferences[scene].group] == scene;
    }

    return loaded;
}
