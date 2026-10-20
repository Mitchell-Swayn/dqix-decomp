#include <globaldefs.h>
// Two-word state observed at incoming r0. Field names remain unknown.
struct Overlay01PairState { unsigned int first; unsigned int second; };
// Original: arm9/ov001 @ 0x021537A0; symbol: func_ov001_021537a0; size: 0x10.
extern "C" void Script_ClearTextTable(Overlay01PairState* state) {
    state->first = 0;
    state->second = 0;
}
