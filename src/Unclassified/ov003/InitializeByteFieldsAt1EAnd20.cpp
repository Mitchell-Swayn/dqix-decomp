#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215EEA0; symbol: func_ov003_0215eea0; size: 0x18.
extern "C" int InitializeByteFieldsAt1EAnd20(void *object) {
    ((unsigned char *)object)[0x1e] = 4;
    ((unsigned char *)object)[0x20] = 0;
    return 7;
}
