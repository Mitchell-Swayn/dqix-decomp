struct FourWordState { int first; int second; int enabled; int fourth; };
// Original: arm9/ov001 @ 0x0215acb4; symbol: func_ov001_0215acb4; size: 0x20
extern "C" void InitializeFourWordState(FourWordState* state)
{
    state->first = -1;
    state->second = -1;
    state->enabled = 1;
    state->fourth = 0;
}
