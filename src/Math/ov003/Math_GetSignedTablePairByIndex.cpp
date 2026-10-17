#include <globaldefs.h>
ARM
extern "C" short data_ov003_0217f3b2[];
extern "C" short data_ov003_0217f3b4[];
// Original: arm9/ov003 @ 0x0215EC68; symbol: func_ov003_0215ec68; size: 0x28.
extern "C" void Math_GetSignedTablePairByIndex(unsigned int index, short* a, short* b) { short x = ((volatile short*)data_ov003_0217f3b2)[index * 2]; short y = ((volatile short*)data_ov003_0217f3b4)[index * 2]; *a = x; *b = y; }
