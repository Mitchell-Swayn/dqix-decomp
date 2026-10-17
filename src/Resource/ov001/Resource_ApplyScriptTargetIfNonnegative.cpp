#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
extern "C" void ResourceHandle_SwitchTargetUnlessBlocked(void* state, int value);
extern "C" void DispatchObjectStateOneOrTwoUnlessFlag4(int object, unsigned value, unsigned unused3, unsigned unused4);
extern "C" char data_02109bf4[];
// Original: arm9/ov001 @ 0x02163640; symbol: func_ov001_02163640; size: 0x68.
extern "C" int Resource_ApplyScriptTargetIfNonnegative(IntegerParameterView* parameter, int type) {
    int value = -1;
    if (type == 2) {
        ReadScriptParameterAsInteger(parameter);
        value = ReadScriptParameterAsInteger((IntegerParameterView*)((char*)parameter + 8));
    } else if (type == 1) {
        value = ReadScriptParameterAsInteger(parameter);
    }
    if (value < 0)
        return 0;
    ResourceHandle_SwitchTargetUnlessBlocked(data_02109bf4, value);
    ((void (*)(int, unsigned))DispatchObjectStateOneOrTwoUnlessFlag4)((int)data_02109bf4, 0);
    return 1;
}
