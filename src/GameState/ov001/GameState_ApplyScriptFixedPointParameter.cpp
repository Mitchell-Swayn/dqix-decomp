#include <globaldefs.h>
ARM
struct FloatParameterView;
extern "C" float ReadScriptParameterAsFloat(FloatParameterView *parameter);
extern "C" void *data_ov001_02165880;
extern "C" void func_ov001_021590fc(void *, int);
// Original: arm9/ov001 @ 0x0215D598; symbol: func_ov001_0215d598; size: 0x38.
extern "C" int GameState_ApplyScriptFixedPointParameter(FloatParameterView *parameter) {
    int value = (int)(4096.0f * ReadScriptParameterAsFloat(parameter));
    func_ov001_021590fc(*(void **)((unsigned char *)&data_ov001_02165880 + 0x24), value);
    return 1;
}
