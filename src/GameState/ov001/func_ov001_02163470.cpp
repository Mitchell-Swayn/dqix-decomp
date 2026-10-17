#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" char *GetBounded1416ByteRecord(int);
extern "C" void func_ov001_0215a6bc(void *, int);
// Original: arm9/ov001 @ 0x02163470; symbol: func_ov001_02163470; size: 0x38.
extern "C" int func_ov001_02163470(void *parameters) {
    char *record = GetBounded1416ByteRecord(ReadScriptParameterAsInteger(parameters));
    if (record == 0) return 0;
    int value = ReadScriptParameterAsInteger((char *)parameters + 8);
    func_ov001_0215a6bc(record, value);
    return 1;
}
