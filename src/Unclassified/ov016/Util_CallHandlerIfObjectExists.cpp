#include <globaldefs.h>
ARM
extern "C" int func_ov016_0218ef14(void *object);
// Original: arm9/ov016 @ 0x0218E660; symbol: func_ov016_0218e660; size: 0x18.
extern "C" int Util_CallHandlerIfObjectExists(void *object) {
    if (!object)
        return 0;
    return func_ov016_0218ef14(object);
}
