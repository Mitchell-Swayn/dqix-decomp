struct Flags { char reserved[0x14]; unsigned int bits; };
struct State { char reserved[0x138]; Flags *flags; };
// Original: arm9/ov026 @ 0x021DCE1C; symbol: func_ov026_021dce1c; size: 0x18.
extern "C" int BattleScene_HasRecoverableAilmentWithTimer5C(State *state) { return (state->flags->bits & 8) != 0; }
