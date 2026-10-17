#include <globaldefs.h>
#pragma force_active on
// tests bit 0x1000 at descriptor offset 0x18.
// Original: arm9/ov024 @ 0x021E05E4; symbol: func_ov024_021e05e4; size: 0x18.
extern "C" int TestDescriptorFlag1000(unsigned char* self) { return ((*(unsigned int**)(self+0x138))[6] & 0x1000) != 0; }
