#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void *parameter);
extern "C" char data_02109bf4[];
extern "C" void InitializeObjectHandlesAndInvalidIndices(int object);
extern "C" void ResourceHandle_StartKeyOperationAndRefreshState(char *p, int key, unsigned int a, unsigned int b);

// Original: arm9/ov001 @ 0x021637A8; symbol: func_ov001_021637a8; size: 0x2C.
extern "C" int Resource_StartKeyOperationFromScriptParameter(void *parameter) {
    int key = ReadScriptParameterAsInteger(parameter);
    char *object = data_02109bf4;
    InitializeObjectHandlesAndInvalidIndices((int)object);
    ((void (*)(char *, int))ResourceHandle_StartKeyOperationAndRefreshState)(object, key);
    return 1;
}
