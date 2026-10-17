// Preserve this unused overlay entry point and the original layout.
#pragma force_active on
#include <globaldefs.h>
#include <Resource/GameResources.h>

struct GameResourcesSlot
{
    unsigned int unknown_0;
    GameResources* instance;
};
extern "C" GameResourcesSlot data_ov017_021d82e0;

// Original: arm9/ov017 @ 0x0218B5A0; symbol: func_ov017_0218b5a0; size: 0x10.
// Stores the GameResources pointer at offset 4 of the overlay global.
extern "C" ARM void GameResources_SetInstance(GameResources* instance)
{
    data_ov017_021d82e0.instance = instance;
}
