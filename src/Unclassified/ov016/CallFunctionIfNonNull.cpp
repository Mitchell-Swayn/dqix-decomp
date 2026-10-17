#include <globaldefs.h>
ARM
extern "C" int func_ov016_0218ef1c(void *);
// Original: arm9/ov016 @ 0x0218E678; symbol: func_ov016_0218e678; size: 0x18.
extern "C" int CallFunctionIfNonNull(void *argument) {
    if (argument == 0)
        return 0;
    return func_ov016_0218ef1c(argument);
}
