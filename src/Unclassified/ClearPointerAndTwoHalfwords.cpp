// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x0207EF60; symbol: func_0207ef60; size: 0x14.
extern "C" void ClearPointerAndTwoHalfwords(char* p){*(int*)p=0;*(short*)(p+6)=0;*(short*)(p+4)=0;}
