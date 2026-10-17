#include <globaldefs.h>
ARM
extern "C" unsigned data_02109bf4;
extern "C" int ReadScriptParameterAsInteger(void *parameter);
extern "C" void Object_SetUnsignedShortAtOffsetCEAndSetUnsignedCharAtOffsetC9To1(int self, unsigned value);
// Original: arm9/ov001 @ 0x02163744; symbol: func_ov001_02163744; size: 0x20.
extern "C" unsigned func_ov001_02163744(void *parameter) {
    unsigned value = ReadScriptParameterAsInteger(parameter);
    Object_SetUnsignedShortAtOffsetCEAndSetUnsignedCharAtOffsetC9To1((int)&data_02109bf4, value);
    return 1;
}
