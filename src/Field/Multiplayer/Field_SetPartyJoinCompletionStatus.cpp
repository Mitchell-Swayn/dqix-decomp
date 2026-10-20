#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021AFB84; symbol: Unclassified_SetByteAtOffset2C; size: 0x8.
// Stores the low byte of the second argument at byte offset 0x2C; text-command dispatcher calls it with selectors 1 and 2.
extern "C" void Field_SetPartyJoinCompletionStatus(void *self, unsigned int value) { *((unsigned char *)self + 0x2c) = value; }
