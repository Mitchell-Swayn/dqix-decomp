#include <globaldefs.h>
ARM
extern "C" void func_ov003_0217e67c(void *object);
// Original: arm9/ov003 @ 0x0217EF0C; symbol: func_ov003_0217ef0c; size: 0x18.
extern "C" void RunObjectActionAndSetByteOne(unsigned char *object) {
    func_ov003_0217e67c(object);
    object[1] = 1;
}
