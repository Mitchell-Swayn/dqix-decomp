#include <globaldefs.h>
ARM
extern "C" signed char data_ov017_021d616c[];
// Original: arm9/ov017 @ 0x0218D2C4; symbol: func_ov017_0218d2c4; size: 0x2C.
extern "C" int Util_GetSignedTableValue1To19(int index) {
    if (index < 1 || index > 19)
        return 0;
    return data_ov017_021d616c[index - 1];
}
