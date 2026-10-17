#include <globaldefs.h>
ARM
extern "C" void *Object_GetGlobalConnectionState(void);
extern "C" int IsFirstWordNonzero(void *object);
extern "C" void SetNestedSecondWordForTypeThree(void *object, int value);
// Original: arm9/ov001 @ 0x02161D8C; symbol: func_ov001_02161d8c; size: 0x24.
extern "C" int GameState_UpdateObjectConnectionStatus(void *object) {
    int connected = IsFirstWordNonzero(Object_GetGlobalConnectionState());
    SetNestedSecondWordForTypeThree(object, connected);
    return 1;
}
