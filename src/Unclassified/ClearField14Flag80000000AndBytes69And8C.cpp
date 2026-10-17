// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x02088BD4; symbol: func_02088bd4; size: 0x1C.
extern "C" void ClearField14Flag80000000AndBytes69And8C(char* p){*(unsigned int*)(p+20)&=~0x80000000u;p[0x69]=0;p[0x8c]=0;}
