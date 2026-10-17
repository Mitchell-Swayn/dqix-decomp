// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x02088914; symbol: func_02088914; size: 0x1C.
extern "C" void ClearField14Flag200AndBytes61And84(char* p){*(unsigned int*)(p+20)&=~0x200u;p[0x61]=0;p[0x84]=0;}
