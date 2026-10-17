#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x0215E3E8; symbol: func_ov001_0215e3e8; size: 0x2C.
extern "C" int Grotto_SetTypeThreeValueFromCurrentObject(void *object) {
    unsigned int current = ReadWordFieldAtOffset1C();
    if (!current)
        return 0;
    SetNestedSecondWordForTypeThree(object, *(int *)(current + 0x9a0));
    return 1;
}
