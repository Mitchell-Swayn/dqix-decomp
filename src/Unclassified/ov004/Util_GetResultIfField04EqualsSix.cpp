#include <globaldefs.h>
ARM
extern "C" void *func_ov004_0215e47c(void *);
extern "C" unsigned OV023_ReadHalfwordField04(void *);
// Original: arm9/ov004 @ 0x0215E4C0; symbol: func_ov004_0215e4c0; size: 0x28.
extern "C" void *Util_GetResultIfField04EqualsSix(void *input) {
    void *result = func_ov004_0215e47c(input);
    if (!result)
        return 0;
    if (OV023_ReadHalfwordField04(result) != 6)
        result = 0;
    return result;
}
