#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void GameState_SetTransferredTreasureMapTypeInvalid(void);
extern "C" unsigned char *GameResources_GetInstance(void);
extern "C" void World_SetIndexedByteValue(unsigned char *, unsigned int);

// Original: arm9/ov004 @ 0x02165AD4; symbol: func_ov004_02165ad4; size: 0x20.
extern "C" int GameState_InvalidateTransferredTreasureMapAndSetWorldByte(void) {
    _ZN9GameState11GetInstanceEv();
    GameState_SetTransferredTreasureMapTypeInvalid();
    World_SetIndexedByteValue(GameResources_GetInstance(), 2);
    return 0;
}
