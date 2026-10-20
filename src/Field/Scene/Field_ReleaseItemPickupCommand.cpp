#include <globaldefs.h>
extern "C" void Field_ReleaseItemPickupSpriteAllocator(void);
ARM
// Original: arm9/ov017 @ 0x021AEE9C; symbol: func_ov017_021aee9c; size: 0xC.
extern "C" void Field_ReleaseItemPickupCommand(void) {
    Field_ReleaseItemPickupSpriteAllocator();
}
