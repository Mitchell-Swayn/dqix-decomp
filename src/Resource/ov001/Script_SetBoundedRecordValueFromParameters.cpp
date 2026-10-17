#include <globaldefs.h>
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" char* GetBounded1416ByteRecord(int);
extern "C" void func_ov001_02159ea8(void*, int);
// Original: arm9/ov001 @ 0x0215BF94; symbol: func_ov001_0215bf94; size: 0x40.
extern "C" int Script_SetBoundedRecordValueFromParameters(void* parameter) {
    int index = ReadScriptParameterAsInteger(parameter);
    int value = ReadScriptParameterAsInteger((char*)parameter + 8);
    char* record = GetBounded1416ByteRecord(index);
    if (!record) return 0;
    func_ov001_02159ea8(record, value);
    return 1;
}
