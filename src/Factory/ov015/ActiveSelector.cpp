#include "SelectorState.h"

extern "C" int func_ov015_0218bc9c(SelectorState* state)
{
    return (state->flags & 0x10) ? state->selector : -1;
}
