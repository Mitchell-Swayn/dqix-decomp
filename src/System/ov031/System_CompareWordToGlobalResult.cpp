#include <globaldefs.h>
ARM
extern "C" int GlobalState7_CallObjectOrReturnMinus56(void);
// Original: arm9/ov031 @ 0x0220FF18; symbol: func_ov031_0220ff18; size: 0x1C.
extern "C" int System_CompareWordToGlobalResult(const unsigned *value) {
    unsigned saved = *value;
    return saved == (unsigned)GlobalState7_CallObjectOrReturnMinus56();
}
