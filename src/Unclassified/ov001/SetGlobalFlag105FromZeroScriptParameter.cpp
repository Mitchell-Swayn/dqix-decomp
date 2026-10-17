#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" ARM int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
// Original: arm9/ov001 @ 0x02161988; symbol: func_ov001_02161988; size: 0x34.
// Sets global byte 0x105 bit zero when the script integer parameter is zero.
extern "C" int SetGlobalFlag105FromZeroScriptParameter(IntegerParameterView* parameter) {
    unsigned char *state = (unsigned char *)ReadGlobalValueAt020FB3F0();
    if (ReadScriptParameterAsInteger(parameter) != 0) state[0x105] &= ~1;
    else state[0x105] |= 1;
    return 1;
}
