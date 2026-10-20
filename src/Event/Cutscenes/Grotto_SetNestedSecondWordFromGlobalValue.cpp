#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);

// Original: arm9/ov001 @ 0x021622D0; symbol: func_ov001_021622d0; size: 0x20.
extern "C" int Grotto_SetNestedSecondWordFromGlobalValue(void *object) {
    int value = *(int *)((unsigned char *)Zone3D_GetMainInstance() + 0x424);
    Script_WriteIntegerReferenceOutput(object, value);
    return 1;
}
