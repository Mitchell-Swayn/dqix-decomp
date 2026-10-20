// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x020890C0; symbol: func_020890c0; size: 0x14.
extern "C" int CombatantState_CanApplyZeroZone(char* p){return !(*(unsigned int*)(p+20)&1);}
