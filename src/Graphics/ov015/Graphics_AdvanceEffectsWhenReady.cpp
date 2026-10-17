#include <globaldefs.h>
ARM
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short* p, unsigned mask);
extern "C" void _ZN8Object3D14AdvanceEffectsEv(void* object);
extern "C" unsigned short data_02114e30;
// Original: arm9/ov015 @ 0x0218E5C0; symbol: func_ov015_0218e5c0; size: 0x4C.
extern "C" void Graphics_AdvanceEffectsWhenReady(void* self) {
    int shouldAdvance = 0;
    if (*(unsigned char*)((char*)self + 0x3A) != 0) {
        if (Object_TestNewlySetHalfwordMask(&data_02114e30, 0x100))
            shouldAdvance = 1;
    } else {
        shouldAdvance = 1;
    }
    if (shouldAdvance)
        _ZN8Object3D14AdvanceEffectsEv(*(void**)((char*)self + 0x24));
}
