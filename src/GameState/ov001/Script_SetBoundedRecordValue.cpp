#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void* parameter);
extern "C" char* GetBounded1416ByteRecord(int index);
extern "C" void func_ov001_0215a3d8(char* record, int value);
// Original: arm9/ov001 @ 0x0215C430; symbol: func_ov001_0215c430; size: 0x38.
extern "C" int Script_SetBoundedRecordValue(void* parameters) {
    int index = ReadScriptParameterAsInteger(parameters);
    char* record = GetBounded1416ByteRecord(index);
    if (record == 0) return 0;
    int value = ReadScriptParameterAsInteger((char*)parameters + 8);
    func_ov001_0215a3d8(record, value);
    return 1;
}
