#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" int TextLookup_TestRecordOrTokenBitFlag(int, unsigned int, unsigned int);
// Original: arm9/main @ 0x02068C30; symbol: func_02068c30; size: 0x3C.
extern "C" bool GameState_TestCurrentObjectValuePredicate(GameState* state, unsigned int unused, unsigned int value) {
    char* object=(char*)state->GetUnknownGameObject();
    if (object != 0) return TextLookup_TestRecordOrTokenBitFlag(0, *reinterpret_cast<unsigned int*>(object+0x134), value) == 0;
    return false;
}
