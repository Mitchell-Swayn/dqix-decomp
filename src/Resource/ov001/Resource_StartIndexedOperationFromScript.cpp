#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" void ResourceHandle_StartIndexedRecordOperation(void *object, int index, void *first, void *second);
extern "C" unsigned char data_02109bf4[];
// Original: arm9/ov001 @ 0x02163518; symbol: func_ov001_02163518; size: 0x28.
extern "C" int Resource_StartIndexedOperationFromScript(IntegerParameterView *parameter) {
    int index = ReadScriptParameterAsInteger(parameter);
    ResourceHandle_StartIndexedRecordOperation(data_02109bf4, index, 0, 0);
    return 1;
}
