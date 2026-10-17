#include <globaldefs.h>
ARM

struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" void ResourceHandle_ApplyPreviousAndNewStateWithValue(void *object, unsigned state, unsigned short value);
typedef void (*ResourceHandleRawCall)(void *, unsigned, unsigned);
extern "C" unsigned char data_02108760[];

// Original: arm9/ov001 @ 0x021637EC; symbol: func_ov001_021637ec; size: 0x5C.
extern "C" int Resource_ApplyScriptParameterState(IntegerParameterView *parameter, int mode) {
    if (mode == 2) {
        unsigned state = ReadScriptParameterAsInteger(parameter);
        unsigned value = ReadScriptParameterAsInteger((IntegerParameterView *)((char *)parameter + 8));
        ((ResourceHandleRawCall)ResourceHandle_ApplyPreviousAndNewStateWithValue)(data_02108760, state, value);
    } else if (mode == 1) {
        unsigned value = ReadScriptParameterAsInteger(parameter);
        ((ResourceHandleRawCall)ResourceHandle_ApplyPreviousAndNewStateWithValue)(data_02108760, value, value);
    }
    return 1;
}
