#include <globaldefs.h>
ARM
extern "C" void Resource_RemoveDisplayStateAndFreeBuffers(void *, int);

// Original: arm9/ov017 @ 0x021AC294; symbol: func_ov017_021ac294; size: 0x14.
extern "C" void func_ov017_021ac294(void *object) {
    ((unsigned char *)object)[1] = 1;
    Resource_RemoveDisplayStateAndFreeBuffers(object, 1);
}
