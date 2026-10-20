#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F79EC; symbol: func_ov023_021f79ec; size: 0x1C.
extern "C" void MenuLayerRecord_BeginTaggedResourceReload(void *object, unsigned int value) {
    *(unsigned int *)((char *)object + 0x10) = value;
    *(unsigned int *)((char *)object + 0x1c) = 0;
    *((unsigned char *)object + 0x0c) |= 3;
}
