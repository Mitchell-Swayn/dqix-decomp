// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x02088890; symbol: func_02088890; size: 0x14.
extern "C" int CombatStatus_CanApplyFizzle(char* p){return !(*(unsigned int*)(p+20)&1);}
