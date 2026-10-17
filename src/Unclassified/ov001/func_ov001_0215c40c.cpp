#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" char *GetBounded1416ByteRecord(int);
extern "C" void func_ov001_0215a3c0(void *);
// Original: arm9/ov001 @ 0x0215C40C; symbol: func_ov001_0215c40c; size: 0x24.
extern "C" int func_ov001_0215c40c(void *parameter) {
    int index = ReadScriptParameterAsInteger(parameter);
    char *record = GetBounded1416ByteRecord(index);
    if (!record) return 0;
    func_ov001_0215a3c0(record);
    return 1;
}
