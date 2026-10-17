#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" char* GetBounded1416ByteRecord(int);
extern "C" void func_ov001_0215a42c(char*, int);
// Original: arm9/ov001 @ 0x0215C4FC; symbol: func_ov001_0215c4fc; size: 0x48.
extern "C" int GameState_ApplyScriptParameterToBoundedRecord(IntegerParameterView* parameters, int parameterIndex) {
    int recordIndex = ReadScriptParameterAsInteger(parameters);
    char* record = GetBounded1416ByteRecord(recordIndex);
    if (!record) return 0;
    int value = 0;
    if (parameterIndex >= 2)
        value = ReadScriptParameterAsInteger((IntegerParameterView*)((char*)parameters + 8));
    func_ov001_0215a42c(record, value);
    return 1;
}
