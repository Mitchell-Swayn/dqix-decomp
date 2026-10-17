#include <globaldefs.h>
extern "C" int ReadWordAtOffset0();
extern "C" int ReadScriptParameterAsInteger(void* state);
extern "C" void ReadScriptParameterAsFloat(void* state);
extern "C" int _ffix();
extern "C" void RecordList_FilterByCategory(int state, int value, int fixed);
// Original: arm9/main @ 0x0209D5DC; symbol: func_0209d5dc; size: 0x48.
extern "C" int Script_FilterRecordsByConvertedFloatThreshold(void* state)
{
    int result = ReadWordAtOffset0();
    if (result == 0) return 0;
    int value = ReadScriptParameterAsInteger(state);
    ReadScriptParameterAsFloat(static_cast<unsigned char*>(state) + 8);
    int fixed = _ffix();
    RecordList_FilterByCategory(result, value, fixed);
    return 1;
}
