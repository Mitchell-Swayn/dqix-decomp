#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x0218B664; symbol: Field_ResetGroupResponseTracking; size: 0x24.
// Resets four response-state bytes and writes the offset-0x4447 sentinel; its exact role remains uncertain.
extern "C" void Field_ResetGroupResponseTracking(signed char* self) {
 self[0x4444]=0;
 self[0x4445]=0;
 self[0x4447]=-1;
 self[0x4448]=0;
 self[0x4449]=0;
}
