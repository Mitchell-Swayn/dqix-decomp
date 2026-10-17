#include <globaldefs.h>
#pragma force_active on
// tests bit four at descriptor offset 0x18.
// Original: arm9/ov024 @ 0x021FB448; symbol: func_ov024_021fb448; size: 0x18.
extern "C" int TestDescriptorFlagFour(unsigned char* self) { return ((*(unsigned int**)(self+0x138))[6] & 4) != 0; }
