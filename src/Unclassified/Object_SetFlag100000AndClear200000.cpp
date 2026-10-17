// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x02088A94; symbol: func_02088a94; size: 0x14.
extern "C" void Object_SetFlag100000AndClear200000(char* p){unsigned int value=*(unsigned int*)(p+20);value|=0x100000;value&=~0x200000u;*(unsigned int*)(p+20)=value;}
