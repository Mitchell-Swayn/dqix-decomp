#include <globaldefs.h>
ARM
extern "C" int func_ov031_022058f0(void *context, unsigned int command, unsigned int parameter, unsigned int mode, unsigned int flags, unsigned int options);
// Original: arm9/ov031 @ 0x0220728C; symbol: func_ov031_0220728c; size: 0x20.
extern "C" int ProcessContextWithDefaultOptions(void *context, unsigned int command, unsigned int parameter) {
    return func_ov031_022058f0(context, command, parameter, 0, 0, 0);
}
