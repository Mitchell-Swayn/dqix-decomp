#include <globaldefs.h>
ARM
extern "C" unsigned data_02109bf4;
extern "C" int ReadScriptParameterAsInteger(void *parameter);
extern "C" unsigned ReplaceValueAndInvalidateFileIndices(unsigned *, void *, unsigned);
// Original: arm9/ov001 @ 0x02163540; symbol: func_ov001_02163540; size: 0x24.
extern "C" unsigned func_ov001_02163540(void *parameter) {
    unsigned value = ReadScriptParameterAsInteger(parameter);
    ReplaceValueAndInvalidateFileIndices(&data_02109bf4, 0, value);
    return 1;
}
