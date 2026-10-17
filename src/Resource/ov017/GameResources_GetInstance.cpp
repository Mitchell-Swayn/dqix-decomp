#include <globaldefs.h>
#include <Resource/GameResources.h>

struct GameResourcesSlot
{
    unsigned int unknown_0;
    GameResources* instance;
};
extern "C" GameResourcesSlot data_ov017_021d82e0;

// Original: arm9/ov017 @ 0x0218B5B0; symbol: func_ov017_0218b5b0; size: 0x10.
// Returns the GameResources pointer stored at offset 4 of the overlay global.
extern "C" ARM GameResources* GameResources_GetInstance()
{
    return data_ov017_021d82e0.instance;
}
