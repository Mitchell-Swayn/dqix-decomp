#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021D4A98; symbol: func_ov017_021d4a98; size: 0x20.
extern "C" void Ov017_AppendTaggedValue(unsigned char *object, unsigned value) {
    *(unsigned *)(*(unsigned **)(object + 0x14)) = 2;
    unsigned *oldCursor = *(unsigned **)(object + 0x14);
    *(unsigned **)(object + 0x14) = *(unsigned **)(object + 0x14) + 2;
    oldCursor[1] = value;
}
