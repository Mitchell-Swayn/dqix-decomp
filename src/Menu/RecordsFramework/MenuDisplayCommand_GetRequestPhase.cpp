#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FD318; symbol: Unclassified_ReadWordAtOffset1C; size: 0x8.
// Returns the 32-bit word stored at byte offset 0x1C.
extern "C" unsigned int MenuDisplayCommand_GetRequestPhase(void *self) { return *(unsigned int *)((unsigned char *)self + 0x1c); }
