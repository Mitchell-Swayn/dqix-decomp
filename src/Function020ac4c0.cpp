#include <std_library_functions.h>
#include "GameState/GameState.h"

extern "C" int func_020ac4c0(void* destination)
{
    memset(destination, 0, 0xb0);

    GameState* state = GameState::GetInstance();
    unsigned char* source = (unsigned char*)state + 0x104;
    source = (unsigned char*)((uintptr_t)source + 0x7400);
    source = (unsigned char*)((uintptr_t)source + 0x3c);
    memcpy(destination, (void*)source, 0xb0);
    return 1;
}
