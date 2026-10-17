#include <globaldefs.h>
ARM
extern "C" unsigned int ReadElement0At02109D8C();
extern "C" int ReadScriptParameterAsInteger(void *parameter);
extern "C" void AppendHalfwordWithinFiftyEntryLimit(short *p, short v);
// Original: arm9/ov023 @ 0x021E9244; symbol: func_ov023_021e9244; size: 0x34.
extern "C" int Script_TryAppendHalfwordParameter(void *parameter) {
    short *entries = (short *)ReadElement0At02109D8C();
    if (entries != 0) {
        int value = ReadScriptParameterAsInteger(parameter);
        AppendHalfwordWithinFiftyEntryLimit(entries, (short)value);
    }
    return 1;
}
