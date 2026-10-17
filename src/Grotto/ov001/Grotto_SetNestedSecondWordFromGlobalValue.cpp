#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt020FB3F0(void);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);

// Original: arm9/ov001 @ 0x021622D0; symbol: func_ov001_021622d0; size: 0x20.
extern "C" int Grotto_SetNestedSecondWordFromGlobalValue(void *object) {
    int value = *(int *)((unsigned char *)ReadGlobalValueAt020FB3F0() + 0x424);
    SetNestedSecondWordForTypeThree(object, value);
    return 1;
}
