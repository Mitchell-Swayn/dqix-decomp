#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x0215E3E8; symbol: func_ov001_0215e3e8; size: 0x2C.
extern "C" int Grotto_SetTypeThreeValueFromCurrentObject(void *object) {
    unsigned int current = TextContext_GetSharedInstance();
    if (!current)
        return 0;
    Script_WriteIntegerReferenceOutput(object, *(int *)(current + 0x9a0));
    return 1;
}
