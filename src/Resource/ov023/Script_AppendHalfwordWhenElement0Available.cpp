#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" unsigned int ReadElement0At02109D8C();
extern "C" void AppendHalfwordWithinFiftyEntryLimit(short *p, short v);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
// Original: arm9/ov023 @ 0x021E915C; symbol: func_ov023_021e915c; size: 0x34.
extern "C" int Script_AppendHalfwordWhenElement0Available(IntegerParameterView* parameter) {
    unsigned int* list = (unsigned int*)ReadElement0At02109D8C();
    if (list != 0) {
        int value = ReadScriptParameterAsInteger(parameter);
        AppendHalfwordWithinFiftyEntryLimit((short*)list, (short)value);
    }
    return 1;
}
