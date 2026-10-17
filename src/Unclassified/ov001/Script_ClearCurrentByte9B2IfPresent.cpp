#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
// Original: arm9/ov001 @ 0x0215E564; symbol: func_ov001_0215e564; size: 0x24.
extern "C" int Script_ClearCurrentByte9B2IfPresent(void) {
    unsigned int object = ReadWordFieldAtOffset1C();
    if (!object)
        return 0;
    *(unsigned char *)(object + 0x19b2) = 0;
    return 1;
}
