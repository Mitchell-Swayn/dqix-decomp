#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int ReadWordAtOffset0(void);
extern "C" int ReadScriptParameterAsInteger(int);
extern "C" void FilterFlaggedSixtyFourByteRecordsByKind(int, int, int);
// Original: arm9/main @ 0x0209D510; symbol: func_0209d510; size: 0x44.
extern "C" int Script_FilterFlag80RecordsByKind(int param) {
    int object = ReadWordAtOffset0();
    if (object == 0) {
        return 0;
    }
    int first = ReadScriptParameterAsInteger(param);
    int second = ReadScriptParameterAsInteger(param + 8);
    FilterFlaggedSixtyFourByteRecordsByKind(object, first, second);
    return 1;
}
