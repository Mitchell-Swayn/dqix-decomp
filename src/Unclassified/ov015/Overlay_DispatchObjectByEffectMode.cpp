#include <globaldefs.h>
ARM
extern "C" void func_ov015_0218e498(void *object);
extern "C" void func_ov015_0218e4f8(void *object);
extern "C" void Graphics_AdvanceEffectsWhenReady(void *object);
extern "C" void Ov015_AdvanceEffectsWhenActive(char *object);
extern "C" void func_ov015_0218e60c(void *object);
extern "C" void func_ov015_0218e670(void *object);
// Original: arm9/ov015 @ 0x0218F1C4; symbol: func_ov015_0218f1c4; size: 0x68.
extern "C" void Overlay_DispatchObjectByEffectMode(void *object) {
    switch (((unsigned char *)object)[0x1c]) {
    case 0: func_ov015_0218e498(object); break;
    case 1: func_ov015_0218e4f8(object); break;
    case 3: Ov015_AdvanceEffectsWhenActive((char *)object); break;
    case 2: Graphics_AdvanceEffectsWhenReady(object); break;
    case 4: func_ov015_0218e60c(object); break;
    case 5: func_ov015_0218e670(object); break;
    case 6: func_ov015_0218e670(object); break;
    }
}
