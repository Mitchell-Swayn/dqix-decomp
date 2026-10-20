#include <globaldefs.h>
ARM

struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" void ResourceHandle_ApplyPreviousAndNewStateWithValue(void *object, unsigned state, unsigned short value);
typedef void (*ResourceHandleRawCall)(void *, unsigned, unsigned);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov001 @ 0x021637EC; symbol: func_ov001_021637ec; size: 0x5C.
extern "C" int Resource_ApplyScriptParameterState(IntegerParameterView *parameter, int mode) {
    if (mode == 2) {
        unsigned state = Script_ReadParameterAsInteger(parameter);
        unsigned value = Script_ReadParameterAsInteger((IntegerParameterView *)((char *)parameter + 8));
        ((ResourceHandleRawCall)ResourceHandle_ApplyPreviousAndNewStateWithValue)(Main_UnknownRoleZeroInitializedStorage, state, value);
    } else if (mode == 1) {
        unsigned value = Script_ReadParameterAsInteger(parameter);
        ((ResourceHandleRawCall)ResourceHandle_ApplyPreviousAndNewStateWithValue)(Main_UnknownRoleZeroInitializedStorage, value, value);
    }
    return 1;
}
