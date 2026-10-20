#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021EA46C; symbol: Combat_ReadStateByteAtOffset839; size: 0x8.
// Returns the byte at offset 0x839; its caller branches on zero versus nonzero during combat update.
extern "C" unsigned int Combat_IsActionMessageResourcesReady(void *self) { return *((unsigned char *)self + 0x839); }
