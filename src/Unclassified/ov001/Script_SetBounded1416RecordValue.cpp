#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" char *GetBounded1416ByteRecord(int);
extern "C" void func_ov001_0215a510(void *, int);
// Original: arm9/ov001 @ 0x0215C820; symbol: func_ov001_0215c820; size: 0x38.
extern "C" bool Script_SetBounded1416RecordValue(void *parameter) {
    int id = ReadScriptParameterAsInteger(parameter);
    char *record = GetBounded1416ByteRecord(id);
    if (record == 0) return false;
    int value = ReadScriptParameterAsInteger((unsigned char *)parameter + 8);
    func_ov001_0215a510(record, value);
    return true;
}
