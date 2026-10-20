#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x0215E414; symbol: func_ov001_0215e414; size: 0x30.
extern "C" int Grotto_SetNestedSecondWordFromResolvedField(void *object) {
    unsigned int record = TextContext_GetSharedInstance(object);
    if (!record)
        return 0;
    int value = *(unsigned char *)*(void **)(record + 0x58);
    Script_WriteIntegerReferenceOutput(object, value);
    return 1;
}
