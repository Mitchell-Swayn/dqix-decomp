#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088ADC; symbol: func_02088adc; size: 0x14.
extern "C" void Object_SetFlag200000AndClear100000(unsigned int* p) { p[5]=(p[5]|0x200000)&~0x100000; }
