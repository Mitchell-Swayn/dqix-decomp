#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" char *GetBounded1416ByteRecord(int i);
extern "C" void func_ov001_0215a69c(char *, int);
// Original: arm9/ov001 @ 0x02163438; symbol: func_ov001_02163438; size: 0x38.
extern "C" int GameState_SetBoundedRecordFromScriptParameters(IntegerParameterView *parameter) {
    int index = ReadScriptParameterAsInteger(parameter);
    char *record = GetBounded1416ByteRecord(index);
    if (record == 0) {
        return 0;
    }
    int value = ReadScriptParameterAsInteger((IntegerParameterView *)((unsigned char *)parameter + 8));
    func_ov001_0215a69c(record, value);
    return 1;
}
