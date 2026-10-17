#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalConnectionState(void);
extern "C" int IsFirstWordNonzero(void*);
extern "C" int ReadIndexedSignedField1038(char*);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov001 @ 0x02160A00; symbol: func_ov001_02160a00; size: 0x48.
extern "C" int GameState_SetConnectionResult(void* output) {
    void* connection = Object_GetGlobalConnectionState();
    int value;
    if (IsFirstWordNonzero(connection) == 0)
        goto setone;
    if (ReadIndexedSignedField1038((char*)connection) != 0)
        goto setzero;
setone:
    value = 1;
    goto done;
setzero:
    value = 0;
done:
    SetNestedSecondWordForTypeThree(output, value);
    return 1;
}
