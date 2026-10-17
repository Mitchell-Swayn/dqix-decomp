#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *);
extern "C" void ForwardValueToAlternateOrEmbeddedResource(void *, void *, int);
extern "C" unsigned char data_ov001_02165958[];
extern "C" unsigned char data_02108760[];
// Original: arm9/ov001 @ 0x02163A18; symbol: func_ov001_02163a18; size: 0x44.
extern "C" int func_ov001_02163a18(IntegerParameterView *parameter) {
    int index = ReadScriptParameterAsInteger(parameter);
    if (index < 0 || index >= 0x10) return 0;
    ForwardValueToAlternateOrEmbeddedResource(data_02108760, data_ov001_02165958 + index * 4, 0);
    return 1;
}
