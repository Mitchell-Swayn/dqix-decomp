#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x0218D618; symbol: func_ov017_0218d618; size: 0x2C.
extern "C" int Ov017_TestNestedWordEqualsTwo(const unsigned char *object) {
    const unsigned *entry = *(const unsigned **)(object + 0x4498);
    if (entry == 0) goto fail;
    if (entry[4] == 2) goto success;
fail:
    return 0;
success:
    return 1;
}
