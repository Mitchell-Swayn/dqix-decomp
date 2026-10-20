#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021BB9EC; symbol: Unclassified_SetHalfwordAtOffset0A; size: 0x8.
// Stores the low halfword of the second argument at offset 0x0A.
extern "C" void FieldEvent_SetPhase(void *self, unsigned int value) { *(unsigned short *)((unsigned char *)self + 0x0a) = value; }
