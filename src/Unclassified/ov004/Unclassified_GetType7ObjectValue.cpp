#include <globaldefs.h>
ARM

extern "C" void *func_ov011_021849c8(void *self);
extern "C" void *func_ov023_021f6880(void *, unsigned int);
extern "C" unsigned int OV023_ReadHalfwordField04(void *);
extern "C" int OV023_ReadHalfwordField28(void *);

// Original: arm9/ov004 @ 0x021634DC; symbol: func_ov004_021634dc; size: 0x40.
extern "C" int Unclassified_GetType7ObjectValue(void *self) {
    void *state = func_ov011_021849c8(self);
    void *object = func_ov023_021f6880(state, 0xa);
    if (object == 0) {
        return 0;
    }
    if (OV023_ReadHalfwordField04(object) != 7) {
        return 0;
    }
    int value = *(short *)((char *)object + 0x5c);
    return OV023_ReadHalfwordField28(object) + (value << 3);
}
