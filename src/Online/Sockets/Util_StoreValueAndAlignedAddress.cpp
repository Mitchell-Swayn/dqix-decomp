#include <globaldefs.h>
ARM
extern "C" unsigned int Network_AlignBufferSizeToWord(unsigned int address);
// Original: arm9/ov031 @ 0x02205620; symbol: func_ov031_02205620; size: 0x28.
extern "C" unsigned int Util_StoreValueAndAlignedAddress(unsigned int base, unsigned int* out, unsigned int value) { out[1] = value ? base : 0; out[0] = value; return base + Network_AlignBufferSizeToWord(value); }
