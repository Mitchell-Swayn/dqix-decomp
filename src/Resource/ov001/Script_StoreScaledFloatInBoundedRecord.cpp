#include <globaldefs.h>
ARM
struct IntegerParameterView; struct FloatParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView*);
extern "C" char* GetBounded1416ByteRecord(int);
extern "C" void InitializeReturnedObjectWith21AndInputAt10(char*, int);
// Original: arm9/ov001 @ 0x0215C858; symbol: func_ov001_0215c858; size: 0x4C.
extern "C" int Script_StoreScaledFloatInBoundedRecord(IntegerParameterView* parameters) {
    int index = ReadScriptParameterAsInteger(parameters);
    char* record = GetBounded1416ByteRecord(index);
    if (record == 0) return 0;
    float value = ReadScriptParameterAsFloat((FloatParameterView*)((char*)parameters + 8));
    InitializeReturnedObjectWith21AndInputAt10(record, (int)(value * 4096.0f));
    return 1;
}
