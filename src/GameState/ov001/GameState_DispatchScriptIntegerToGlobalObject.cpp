#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" unsigned char data_ov001_02165880[];
extern "C" void func_ov001_0215905c(void *object, int value);
// Original: arm9/ov001 @ 0x0215D784; symbol: func_ov001_0215d784; size: 0x24.
extern "C" int GameState_DispatchScriptIntegerToGlobalObject(IntegerParameterView *parameter) {
    int value = ReadScriptParameterAsInteger(parameter);
    void *object = *(void **)(data_ov001_02165880 + 0x24);
    func_ov001_0215905c(object, value);
    return 1;
}
