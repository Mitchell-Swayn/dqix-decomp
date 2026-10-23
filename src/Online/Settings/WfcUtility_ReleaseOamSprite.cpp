#include <globaldefs.h>
ARM
#pragma force_active on
// Original data: arm9/ov031 @ 0x02290d60; symbol: data_ov031_02290d60.
// Initial value: zero-filled at load; runtime pointer or shared state storage.
// Field offsets and indexed loads follow the original instructions.
// Full initial contents and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage;
extern "C" void PushPointerIntoInterruptProtectedRing(void *, void *);
// Original: arm9/ov031 @ 0x0223DA58; symbol: func_ov031_0223da58; size: 0x4C.
// Disables an OAM sprite and returns it to the appropriate screen pointer pool.
extern "C" void WfcUtility_ReleaseOamSprite(void *sprite)
{
    unsigned *attributes = (unsigned *)sprite;
    attributes[0] = (attributes[0] & 0xc1fffcff) | 0x200;
    unsigned char *context = WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage;
    unsigned screen = 0;
    if ((unsigned)sprite >= (unsigned)(context + 0x400)) screen = 1;
    PushPointerIntoInterruptProtectedRing(*(void **)(context + 0x800 + screen * 4), sprite);
}
#pragma force_active reset
