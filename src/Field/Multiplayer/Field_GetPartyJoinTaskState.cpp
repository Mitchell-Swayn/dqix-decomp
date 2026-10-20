#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B05BC; symbol: Unclassified_ReadByteAtOffset0A; size: 0x8.
// Returns the unsigned byte at offset 0x0A.
extern "C" unsigned int Field_GetPartyJoinTaskState(void *self) { return *((unsigned char *)self + 0x0a); }
