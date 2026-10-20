#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0216F208; symbol: Combat_GetAddressAtOffset264; size: 0x8.
// Returns the object address plus byte offset 0x264; the caller uses this embedded address in combat handling.
ARM
extern "C" void *BattleCamera_GetDesiredOrbitParameters(void *object) {
    return (unsigned char *)object + 0x264;
}
