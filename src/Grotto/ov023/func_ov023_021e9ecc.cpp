#include <globaldefs.h>
ARM
extern "C" int GameState_CopyFourByteFieldAtOffset7AC0(void *dest);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021E9ECC; symbol: func_ov023_021e9ecc; size: 0x34.
extern "C" int func_ov023_021e9ecc(void *out) {
    int value = 0;
    GameState_CopyFourByteFieldAtOffset7AC0(&value);
    SetNestedSecondWordForTypeThree(out, value);
    return 1;
}
