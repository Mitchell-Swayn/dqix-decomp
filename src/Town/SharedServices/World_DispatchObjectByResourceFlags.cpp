#include <globaldefs.h>
ARM
extern "C" int PollSubScreenPoolAndCanvasTransition(void *);
extern "C" int Tavern_FadeOutPartyPreviewAndReleaseResources(void *);
// Original: arm9/ov003 @ 0x02160CC0; symbol: World_DispatchObjectByResourceFlags; size: 0x38.
// Dispatches by object flags at +0x464, preferring bit 0x400 over bit 0x800.
extern "C" int World_DispatchObjectByResourceFlags(const unsigned char *object) {
    unsigned flags = *(const unsigned *)(object + 0x464);
    int result = 1;
    if (flags & 0x400)
        result = PollSubScreenPoolAndCanvasTransition((void *)object);
    else if (flags & 0x800)
        result = Tavern_FadeOutPartyPreviewAndReleaseResources((void *)object);
    return result;
}
