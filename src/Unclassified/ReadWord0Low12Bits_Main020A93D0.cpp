#include <globaldefs.h>
ARM
struct Bits { unsigned int value:12; unsigned int rest:20; };
// Original: arm9/main @ 0x020A93D0; symbol: func_020a93d0; size: 0x10.
 extern "C" unsigned int ReadWord0Low12Bits_Main020A93D0(Bits* p) { return p->value; }
