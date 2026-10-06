#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff94(GameState* state, int index);
extern "C" void* func_02010828(GameState* state);

extern "C" int func_ov003_02160b84()
{
    GameState* state = GameState::GetInstance();
    int presentCount = 0;
    for (int index = 0; index < 4; ++index) {
        if (func_0200ff94(state, index) != NULL)
            ++presentCount;
    }

    unsigned char listedCount =
        *((unsigned char*)func_02010828(GameState::GetInstance()) + 0xf7c);
    return presentCount - listedCount;
}
