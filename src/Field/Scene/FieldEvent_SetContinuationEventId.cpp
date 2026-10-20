#include <globaldefs.h>
// Stores the supplied halfword at object offset 0x11A.
// Original: arm9/ov017 @ 0x021bbbec; symbol: func_ov017_021bbbec; size: 0xc.
extern "C" void FieldEvent_SetContinuationEventId(unsigned char* p, unsigned short value) { *(unsigned short*)(p + 0x11a) = value; }
