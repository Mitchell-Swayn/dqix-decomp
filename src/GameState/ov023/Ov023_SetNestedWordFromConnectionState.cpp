#include <globaldefs.h>
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int IsFirstWordNonzero(void*);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov023 @ 0x021EA8E8; symbol: func_ov023_021ea8e8; size: 0x38.
extern "C" ARM int Ov023_SetNestedWordFromConnectionState(void* owner) {
    int active = IsFirstWordNonzero(Object_GetGlobalConnectionState());
    if (active) {
        SetNestedSecondWordForTypeThree(owner, 1);
        return 1;
    }
    SetNestedSecondWordForTypeThree(owner, 0);
    return 1;
}
