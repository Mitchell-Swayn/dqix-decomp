#include <globaldefs.h>
ARM
extern "C" void ResetEmbeddedResourceAndRecord(int);

// Original: arm9/ov023 @ 0x021F8130; symbol: func_ov023_021f8130; size: 0x10.
extern "C" void func_ov023_021f8130(int object) {
    ResetEmbeddedResourceAndRecord(object + 0x20);
}
