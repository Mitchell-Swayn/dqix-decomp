#include <globaldefs.h>
ARM
#pragma optimization_level 3
extern "C" int ReadWordAtOffset0(void);
extern "C" int FilterSixtyFourByteRecordsByKind(int, int, int);
extern "C" int ReadScriptParameterAsInteger(void *);
// Original: arm9/main @ 0x0209CE34; symbol: func_0209ce34; size: 0x44.
extern "C" int Script_FilterRecordsByKind(void *param1) {
    int state = ReadWordAtOffset0();
    if (state == 0) return 0;
    int first = ReadScriptParameterAsInteger(param1);
    int second = ReadScriptParameterAsInteger((char *)param1 + 8);
    FilterSixtyFourByteRecordsByKind(state, first, second);
    return 1;
}
