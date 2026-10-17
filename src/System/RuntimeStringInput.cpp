#include "System/RuntimeStringInput.h"

#pragma optimize_for_size off

// Original: arm9/main @ 0x02003D58; symbol: func_02003d58; size: 0x84.
extern "C" int RuntimeStringInput_ReadUnreadOrTestEnd(RuntimeStringInputState* state, int value, int operation)
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
