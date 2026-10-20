#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021ED314; symbol: Unclassified_SetWordAtOffset164; size: 0x8.
// Stores the second argument as a 32-bit word at byte offset 0x164.
extern "C" void Combat_BindMessageActionRecord(void *self, unsigned int value) { *(unsigned int *)((unsigned char *)self + 0x164) = value; }
