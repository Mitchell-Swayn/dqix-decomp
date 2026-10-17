#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
struct PackedState { char pad[0x100]; unsigned low : 12; unsigned middle : 4; unsigned high : 5; unsigned reserved : 11; };
struct Root { char pad[12]; PackedState *state; };
extern "C" Root data_ov023_021fff08;
// Original: arm9/ov023 @ 0x021F57C4; symbol: func_ov023_021f57c4; size: 0x84.
extern "C" int Script_SetPackedStateFields(char *params) {
    data_ov023_021fff08.state->low = _ZNK6Script9Parameter5ToIntEv(params);
    data_ov023_021fff08.state->middle = _ZNK6Script9Parameter5ToIntEv(params + 8);
    data_ov023_021fff08.state->high = _ZNK6Script9Parameter5ToIntEv(params + 16);
    return 1;
}
