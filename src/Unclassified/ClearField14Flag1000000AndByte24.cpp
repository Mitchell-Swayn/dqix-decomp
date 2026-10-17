// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x020881AC; symbol: func_020881ac; size: 0x18.
extern "C" void ClearField14Flag1000000AndByte24(char* p){*(unsigned int*)(p+20)&=~0x1000000u;p[36]=0;}
