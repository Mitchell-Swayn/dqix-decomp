#include <globaldefs.h>
ARM
extern "C" int func_ov016_0218f16c(void *);
// Original: arm9/ov016 @ 0x0218E708; symbol: func_ov016_0218e708; size: 0x24.
extern "C" unsigned int Resource_IsNonNullAndHelperReturnsOne(void *object) {
    if (object == 0)
        return 0;
    return func_ov016_0218f16c(object) == 1;
}
