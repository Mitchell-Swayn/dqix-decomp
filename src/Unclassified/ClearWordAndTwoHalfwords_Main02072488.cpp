// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x02072488; symbol: func_02072488; size: 0x14.
extern "C" void ClearWordAndTwoHalfwords_Main02072488(char* p){*(int*)p=0;*(short*)(p+4)=0;*(short*)(p+6)=0;}
