#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" char *GetBounded1416ByteRecord(int index);
extern "C" void SetReturnedObjectWordTo12IfPresent(char *record);
// Original: arm9/ov001 @ 0x0215C3E8; symbol: func_ov001_0215c3e8; size: 0x24.
extern "C" int GameState_ProcessScriptSelectedRecord(IntegerParameterView *parameter) {
    int index = ReadScriptParameterAsInteger(parameter);
    char *record = GetBounded1416ByteRecord(index);
    if (!record)
        return 0;
    SetReturnedObjectWordTo12IfPresent(record);
    return 1;
}
