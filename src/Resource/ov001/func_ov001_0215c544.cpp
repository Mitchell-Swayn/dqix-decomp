#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *);
extern "C" char *GetBounded1416ByteRecord(int);
extern "C" void func_ov001_0215a530(void *, int);
// Original: arm9/ov001 @ 0x0215C544; symbol: func_ov001_0215c544; size: 0x38.
extern "C" int func_ov001_0215c544(IntegerParameterView *parameter) {
    char *record = GetBounded1416ByteRecord(ReadScriptParameterAsInteger(parameter));
    if (record == 0) return 0;
    int value = ReadScriptParameterAsInteger((IntegerParameterView *)((char *)parameter + 8));
    func_ov001_0215a530(record, value);
    return 1;
}
