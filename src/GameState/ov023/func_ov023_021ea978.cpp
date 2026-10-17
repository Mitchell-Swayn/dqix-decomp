#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt020FB3F0(void);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021EA978; symbol: func_ov023_021ea978; size: 0x38.
extern "C" int func_ov023_021ea978(void *obj) {
    int value = *(short *)ReadGlobalValueAt020FB3F0();
    int rounded = value - value % 100;
    SetNestedSecondWordForTypeThree(obj, (short)rounded);
    return 1;
}
