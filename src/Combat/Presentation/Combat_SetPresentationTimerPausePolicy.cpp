#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021ED11C; symbol: Unclassified_SetByteAtOffset301; size: 0x8.
// Stores the low byte of the second argument at offset 0x301.
extern "C" void Combat_SetPresentationTimerPausePolicy(void *self, unsigned int value) { *((unsigned char *)self + 0x301) = value; }
