#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0203CE00; symbol: func_0203ce00; size: 0x14.
extern "C" unsigned int Object_SelectWord24Or25ByFlag(unsigned int* p) { return p[23] & 2 ? p[25] : p[24]; }
