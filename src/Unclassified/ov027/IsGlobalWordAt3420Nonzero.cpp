#include <globaldefs.h>
extern "C" unsigned char data_ov027_021e3420[];
// Original: arm9/ov027 @ 0x021dd3b0; symbol: func_ov027_021dd3b0; size: 0x1c.
extern "C" int IsGlobalWordAt3420Nonzero() { return *(unsigned*)data_ov027_021e3420 != 0; }
