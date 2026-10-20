#include <globaldefs.h>
#include <GameState/GameState.h>

extern "C" int TextLookup_TestRecordOrTokenBitFlag(int, unsigned int, int);

// Original: arm9/main @ 0x02068BF4; symbol: func_02068bf4; size: 0x3C.
extern "C" int GameState_TestProtagonistResolvedValueStatusZero(GameState *state, int, int value) {
    GameObject *object=state->GetProtagonist();
    if (object != 0)
        return TextLookup_TestRecordOrTokenBitFlag(0, *(unsigned int *)((char *)object+0x134), value) == 0;
    return 0;
}
