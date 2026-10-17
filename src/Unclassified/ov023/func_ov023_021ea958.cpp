#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt020FB3F0(void);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021EA958; symbol: func_ov023_021ea958; size: 0x20.
extern "C" int func_ov023_021ea958(void *p) {
    unsigned int value = *(unsigned short *)ReadGlobalValueAt020FB3F0();
    SetNestedSecondWordForTypeThree(p, value);
    return 1;
}
