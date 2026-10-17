// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x0208B4C0; symbol: func_0208b4c0; size: 0x14.
extern "C" void ClearFieldB0AndInvalidateFieldAC(char* p){*(int*)(p+0xb0)=0;*(int*)(p+0xac)=-1;}
