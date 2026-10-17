#include <globaldefs.h>
ARM
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short *, unsigned int);
extern "C" void _ZN8Object3D14AdvanceEffectsEv(void *);
extern "C" unsigned short data_02114e30;
// Original: arm9/ov015 @ 0x0218E574; symbol: func_ov015_0218e574; size: 0x4C.
extern "C" void Ov015_AdvanceEffectsWhenActive(char *object) {
    int active = 0;
    if (*(unsigned char *)(object + 0x3a)) {
        if (Object_TestNewlySetHalfwordMask(&data_02114e30, 0x100)) active = 1;
    } else {
        active = 1;
    }
    if (active) _ZN8Object3D14AdvanceEffectsEv(*(void **)(object + 0x24));
}
