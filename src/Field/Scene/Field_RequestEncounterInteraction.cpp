#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x0219AA6C; symbol: func_ov017_0219aa6c; size: 0x10.
extern "C" void Field_RequestEncounterInteraction(void *base) {
    *((unsigned char *)base + 0x42e6) = 1;
}
