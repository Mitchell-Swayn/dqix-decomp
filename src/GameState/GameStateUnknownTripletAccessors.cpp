#include "GameState/GameState.h"

extern "C" char* func_0205ec34();

extern "C" void func_02010774(GameState* state, unsigned int value)
{
    *((unsigned int*)((char*)state + 0x5cb0)) = value;
    char* record = func_0205ec34();
    unsigned char count = *((unsigned char*)record + 0x332);
    *((unsigned char*)record + count * 0x1c) = value;
}

extern "C" unsigned int func_0201079c(GameState* state)
{
    return *((unsigned int*)((char*)state + 0x5cb0));
}

extern "C" void func_020107a8(GameState* state, unsigned int value)
{
    *((unsigned int*)((char*)state + 0x5cb4)) = value;
    char* record = func_0205ec34();
    unsigned char count = *((unsigned char*)record + 0x332);
    *((unsigned char*)record + count * 0x1c + 1) = value;
}

extern "C" unsigned int func_020107d0(GameState* state)
{
    return *((unsigned int*)((char*)state + 0x5cb4));
}

extern "C" void func_020107dc(GameState* state, unsigned int value)
{
    *((unsigned int*)((char*)state + 0x5cb8)) = value;
    char* record = func_0205ec34();
    unsigned char count = *((unsigned char*)record + 0x332);
    *((unsigned char*)record + count * 0x1c + 2) = value;
}

extern "C" unsigned int func_02010804(GameState* state)
{
    return *((unsigned int*)((char*)state + 0x5cb8));
}

extern "C" void func_02010810(GameState* state, unsigned int value)
{
    *((unsigned int*)((char*)state + 0x5cbc)) = value;
}

extern "C" unsigned int func_0201081c(GameState* state)
{
    return *((unsigned int*)((char*)state + 0x5cbc));
}
