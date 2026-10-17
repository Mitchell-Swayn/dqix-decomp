#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021CC1D8; symbol: func_ov017_021cc1d8; size: 0x20.
extern "C" void func_ov017_021cc1d8(void *, const char *record, int, void *base) {
    char *object = *(char **)((char *)base + 0x3b2c);
    if (*(signed char *)(object + 0x10) == *(unsigned char *)(record + 4))
        *(unsigned char *)(object + 0xf) = *(unsigned int *)(record + 8);
}
