#include <globaldefs.h>
// Clears a halfword and the two following bytes.
// Original: arm9/ov023 @ 0x021E71A0; symbol: func_ov023_021e71a0; size: 0x14.
extern "C" void TimeRecord_ClearDuration(void* record) { *(unsigned short*)record=0; ((unsigned char*)record)[2]=0; ((unsigned char*)record)[3]=0; }
