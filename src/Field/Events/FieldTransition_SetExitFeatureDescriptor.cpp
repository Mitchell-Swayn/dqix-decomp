#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021AB698; symbol: Unclassified_SetWordAtOffset10; size: 0x8.
// Stores the second argument as a 32-bit word at byte offset 0x10.
extern "C" void FieldTransition_SetExitFeatureDescriptor(void *self, unsigned int value) { *(unsigned int *)((unsigned char *)self + 0x10) = value; }
