#include <globaldefs.h>
ARM
// Sets the selected bit in the byte at receiver offset 0x4331.
// Original: arm9/ov017 @ 0x0218d4b8; symbol: func_ov017_0218d4b8; size: 0x18.
extern "C" ARM void Field_SetPartyMemberMessageFlag(void* self, unsigned int bit) { unsigned char* value = (unsigned char*)self + 0x4331; *value = (unsigned char)(*value | (1u << bit)); }
