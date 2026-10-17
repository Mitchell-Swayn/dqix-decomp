#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x0215E414; symbol: func_ov001_0215e414; size: 0x30.
extern "C" int Grotto_SetNestedSecondWordFromResolvedField(void *object) {
    unsigned int record = ReadWordFieldAtOffset1C(object);
    if (!record)
        return 0;
    int value = *(unsigned char *)*(void **)(record + 0x58);
    SetNestedSecondWordForTypeThree(object, value);
    return 1;
}
