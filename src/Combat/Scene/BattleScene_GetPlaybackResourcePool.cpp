#include <globaldefs.h>
// Original: arm9/ov000 @ 0x02160F00; symbol: Combat_GetAddressAtOffsetB30; size: 0x8.
// Returns the object address plus byte offset 0xb30, as used by combat selection handling.
ARM
extern "C" void *BattleScene_GetPlaybackResourcePool(void *object) {
    return (unsigned char *)object + 0xb30;
}
