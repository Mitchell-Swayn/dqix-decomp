struct Flags { char reserved[0x18]; unsigned int bits; };
struct State { char reserved[0x138]; Flags *flags; };
// Original: arm9/ov026 @ 0x021DD3C4; symbol: func_ov026_021dd3c4; size: 0x18.
extern "C" int BattleScene_IsCombatantExcludedFromEncounterSelection(State *state) { return (state->flags->bits & 8192) != 0; }
