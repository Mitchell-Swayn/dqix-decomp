#include "GameState/GameState.h"

extern "C" void* func_02010828(GameState* state);

extern "C" signed char func_02039730(void* self, int index)
{
    GameState* state = GameState::GetInstance();
    char* bytes = (char*)func_02010828(state) + index + 0x2c00;
    return ((signed char*)bytes)[0x8d];
}
