#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt020FB3F0();
extern "C" void *GameResources_GetInstance();
extern "C" void ClearWordAtOffset4MaskedBits(int, unsigned int);
// Original: arm9/ov017 @ 0x021B2AD8; symbol: func_ov017_021b2ad8; size: 0x3C.
extern "C" int func_ov017_021b2ad8(void *self) {
    if (*(unsigned int *)((char *)ReadGlobalValueAt020FB3F0() + 0x424) != 0)
        return (int)*(unsigned int *)((char *)self + 8);
    ClearWordAtOffset4MaskedBits((int)GameResources_GetInstance(), 2);
    *(unsigned int *)((char *)self + 0x38) &= ~1;
    return 3;
}
