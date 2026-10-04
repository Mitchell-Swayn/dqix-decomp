#include "System/RuntimeStringInput.h"

#pragma optimize_for_size off

extern "C" int func_02003d58(RuntimeStringInputState* state, int value, int operation)
{
    switch (operation) {
    case 0: {
        char next = *state->cursor;
        if (next == 0) {
            state->endOfInput = 1;
            return -1;
        }
        ++state->cursor;
        return (unsigned char)next;
    }
    case 1:
        if (!state->endOfInput) {
            --state->cursor;
        } else {
            state->endOfInput = 0;
        }
        return value;
    case 2:
        return state->endOfInput;
    default:
        return 0;
    }
}
