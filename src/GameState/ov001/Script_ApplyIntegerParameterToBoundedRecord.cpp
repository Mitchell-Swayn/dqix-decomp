#include <globaldefs.h>
ARM
struct IntegerParameterView { unsigned type; union { int integer; float real; } value; };
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *);
extern "C" char *GetBounded1416ByteRecord(int);
extern "C" void func_ov001_0215a6dc(void *, int);
// Original: arm9/ov001 @ 0x021634A8; symbol: func_ov001_021634a8; size: 0x38.
extern "C" int Script_ApplyIntegerParameterToBoundedRecord(IntegerParameterView *parameter) {
    int index = ReadScriptParameterAsInteger(parameter);
    char *record = GetBounded1416ByteRecord(index);
    if (!record) return 0;
    int value = ReadScriptParameterAsInteger((IntegerParameterView *)((char *)parameter + 8));
    func_ov001_0215a6dc(record, value);
    return 1;
}
