#include <globaldefs.h>
ARM

extern "C" void *func_ov011_021849c8(void *self);
extern "C" void *func_ov023_021f6880(void *, unsigned int);
extern "C" unsigned int OV023_ReadHalfwordField04(void *);
extern "C" void Ov023_ForwardObjectAt20(void *, int);

// Original: arm9/ov004 @ 0x02154210; symbol: func_ov004_02154210; size: 0x40.
extern "C" int Unclassified_ForwardObjectWithField04Value16(void *self) {
    void *state = func_ov011_021849c8(self);
    void *object = func_ov023_021f6880(state, 0x2e);
    if (object == 0) {
        return 0;
    }
    if (OV023_ReadHalfwordField04(object) != 0x10) {
        return 0;
    }
    Ov023_ForwardObjectAt20(object, -1);
    return 0;
}
