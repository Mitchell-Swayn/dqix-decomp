#include "GameState/GameState.h"

extern "C" void* func_0200fbb4(void* destination, const void* source);

extern "C" void* func_0200fba4(GameState* state, const void* source)
{
    return func_0200fbb4(state->unk_3f8, source);
}
