// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x02088B50; symbol: func_02088b50; size: 0x14.
extern "C" int CombatantState_CanApplyFocusPocus(char* p){return !(*(unsigned int*)(p+20)&1);}
