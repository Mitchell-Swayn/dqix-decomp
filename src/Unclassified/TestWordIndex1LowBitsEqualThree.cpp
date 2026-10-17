#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0204BDF0; symbol: func_0204bdf0; size: 0x18.
bool TestWordIndex1LowBitsEqualThree(unsigned short *p){return (p[1]&31)==3;}
}
