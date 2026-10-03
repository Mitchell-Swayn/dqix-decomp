#include "GameState/GameState.h"

typedef char GameStateUnknownByteAccessorOffsetCheck[
    offsetof(GameState, unk_5722) == 0x5722 ? 1 : -1];

extern "C" void func_0201075c(GameState* state, unsigned char value)
{
    state->unk_5722[7] = value;
}
