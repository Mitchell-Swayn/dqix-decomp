#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" int func_02067fec(int, unsigned int, unsigned int);
ARM
// Original: arm9/main @ 0x020689E4; symbol: func_020689e4; size: 0x3C.
extern "C" bool TestProtagonistResourceLookupSuccess(GameState *game, unsigned int ignored, unsigned int key) {
    GameObject *object=game->GetProtagonist(); if (!object) return false;
    return func_02067fec(0,*(unsigned int *)((char *)object+0x134),key)==0;
}
