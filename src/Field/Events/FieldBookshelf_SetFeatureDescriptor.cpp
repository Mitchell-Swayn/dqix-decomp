#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021ACA14; symbol: Unclassified_SetWordAtOffset08; size: 0x8.
// Stores the second argument as a 32-bit word at byte offset 8.
extern "C" void FieldBookshelf_SetFeatureDescriptor(void *self, unsigned int value) { *(unsigned int *)((unsigned char *)self + 8) = value; }
