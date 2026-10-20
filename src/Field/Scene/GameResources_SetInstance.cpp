// Preserve this unused overlay entry point and the original layout.
#pragma force_active on
#include <globaldefs.h>
#include <Resource/GameResources.h>

struct GameResourcesSlot
{
    unsigned int unknown_0;
    GameResources* instance;
};
// Original data: arm9/ov017 @ 0x21d82e0; symbol: data_ov017_021d82e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" GameResourcesSlot FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov017 @ 0x0218B5A0; symbol: func_ov017_0218b5a0; size: 0x10.
// Stores the GameResources pointer at offset 4 of the overlay global.
extern "C" ARM void GameResources_SetInstance(GameResources* instance)
{
    FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage.instance = instance;
}
