#include <globaldefs.h>
ARM
extern "C" void PartyTalk_RefreshProfileSessionRendering(void *object);
// Original: arm9/ov017 @ 0x021A99B0; symbol: func_ov017_021a99b0; size: 0x18.
extern "C" void Field_RefreshOverlayEightActivityText(void *object) {
    void *activity = *(void **)((char *)object + 0x20);
    if (activity)
        PartyTalk_RefreshProfileSessionRendering(activity);
}
