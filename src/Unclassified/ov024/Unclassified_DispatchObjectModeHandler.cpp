#include <globaldefs.h>
ARM

extern "C" unsigned char data_ov024_021ffda4[];

// Original: arm9/ov024 @ 0x021F736C; symbol: func_ov024_021f736c; size: 0x4C.
extern "C" int Unclassified_DispatchObjectModeHandler(void *object) {
    void *state = *(void **)((char *)object + 0x10);
    if (state == 0) {
        return 0;
    }
    unsigned int index = (*(unsigned int *)((char *)state + 0x18) << 5) >> 23;
    if (index >= 0x42) {
        return 0;
    }
    void (*handler)(void *) = *(void (**)(void *))(data_ov024_021ffda4 + index * 4);
    if (handler == 0) {
        return 0;
    }
    return ((int (*)(void *))handler)(object);
}
