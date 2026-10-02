#include "GameState/GameState.h"

extern "C" void* func_0200fbb4(void* destination, const void* source);

extern "C" void* func_0200fcfc(GameState* state, const void* source)
{
    return func_0200fbb4((char*)state + 0x3f8, source);
}

extern "C" void* func_0200fd0c(GameState* state)
{
    return (char*)state + 0x3f8;
}
