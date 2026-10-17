#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" void *Object_GetGlobalThirtyTwoEntryContainer(void);
extern "C" int FindChildIndexByHalfwordKeyExcludingFlag8000(char *, int);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x0215FA10; symbol: func_ov001_0215fa10; size: 0x30.
extern "C" int SetObjectNestedWordToChildIndexFromScriptParameter(void *object) {
    int key = ReadScriptParameterAsInteger(object);
    void *container = Object_GetGlobalThirtyTwoEntryContainer();
    int index = FindChildIndexByHalfwordKeyExcludingFlag8000((char *)container, key);
    SetNestedSecondWordForTypeThree((char *)object + 8, index);
    return 1;
}
