#include <globaldefs.h>
ARM
extern "C" int func_ov023_021e6194(void);
// Original: arm9/ov023 @ 0x021E4E20; symbol: func_ov023_021e4e20; size: 0x1C.
extern "C" int Util_GetNonNullPointerAtOffset128(void *a0) {
    if (!*(void **)((char *)a0 + 0x128))
        return 0;
    return func_ov023_021e6194();
}
