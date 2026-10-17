#include <globaldefs.h>
ARM
extern "C" char *_ZN15LightingManager11GetInstanceEv(void);
extern "C" void _ZN15LightingManager9BeginFadeEst(void *, int, unsigned int);
extern "C" void *ReadOverlayControlSecondWord(void);
// Original: arm9/ov025 @ 0x021E74F4; symbol: func_ov025_021e74f4; size: 0x2C.
extern "C" int Graphics_BeginLightingFadeAndSetOverlayFlag(void *params) {
    _ZN15LightingManager9BeginFadeEst(_ZN15LightingManager11GetInstanceEv(), *(short *)((char *)params + 8), *(unsigned short *)((char *)params + 0xa));
    *(unsigned char *)((char *)ReadOverlayControlSecondWord() + 0x6fd4) = 1;
    return 1;
}
