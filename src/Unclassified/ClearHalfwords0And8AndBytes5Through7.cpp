// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x02039EE8; symbol: func_02039ee8; size: 0x1C.
extern "C" void ClearHalfwords0And8AndBytes5Through7(char* p){*(short*)p=0;p[5]=0;p[6]=0;*(short*)(p+8)=0;p[7]=0;}
