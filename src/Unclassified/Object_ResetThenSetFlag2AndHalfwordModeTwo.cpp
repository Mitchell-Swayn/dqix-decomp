// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x02088560; symbol: func_02088560; size: 0x38.
extern "C" void Object_ResetThenSetFlag2AndHalfwordModeTwo(char* p){*(unsigned int*)(p+20)&=~2u;*(unsigned short*)(p+34)&=~3;*(unsigned int*)(p+20)|=2;*(unsigned short*)(p+34)=(*(unsigned short*)(p+34)&~3)|2;}
