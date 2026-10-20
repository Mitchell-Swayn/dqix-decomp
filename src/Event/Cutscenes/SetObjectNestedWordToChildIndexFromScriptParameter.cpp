#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" void *ActorPool_GetGlobalInstance(void);
extern "C" int FindChildIndexByHalfwordKeyExcludingFlag8000(char *, int);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x0215FA10; symbol: func_ov001_0215fa10; size: 0x30.
extern "C" int SetObjectNestedWordToChildIndexFromScriptParameter(void *object) {
    int key = Script_ReadParameterAsInteger(object);
    void *container = ActorPool_GetGlobalInstance();
    int index = FindChildIndexByHalfwordKeyExcludingFlag8000((char *)container, key);
    Script_WriteIntegerReferenceOutput((char *)object + 8, index);
    return 1;
}
