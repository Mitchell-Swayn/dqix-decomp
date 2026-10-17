#include <globaldefs.h>
ARM
extern "C" void *Object_GetGlobalConnectionState(void);
extern "C" bool TestActiveWordAndGlobalStateNonzero(unsigned int *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021EA920; symbol: func_ov023_021ea920; size: 0x38.
extern "C" int UpdateTypeThreeFromConnectionState(void *object) {
    unsigned int *state = (unsigned int *)Object_GetGlobalConnectionState();
    if (TestActiveWordAndGlobalStateNonzero(state)) {
        SetNestedSecondWordForTypeThree(object, 1);
    } else {
        SetNestedSecondWordForTypeThree(object, 0);
    }
    return 1;
}
