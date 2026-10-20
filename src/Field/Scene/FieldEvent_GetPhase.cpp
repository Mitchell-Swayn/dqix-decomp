#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021BB9F4; symbol: Unclassified_ReadHalfwordAtOffset0A; size: 0x8.
// Returns the unsigned halfword at offset 0x0A; callers compare this record field with state value 5.
extern "C" unsigned int FieldEvent_GetPhase(void *self) { return *(unsigned short *)((unsigned char *)self + 0x0a); }
