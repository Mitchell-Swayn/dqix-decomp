#include <globaldefs.h>
ARM
struct FloatParameterView;
struct IntegerParameterView;
struct GameState;
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetField3B0ObjectWithFlag4(GameState *);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView *parameter);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" void Object_SetAngleAndDeferredUpdateFlag(void *object, unsigned angle, int pending);
// Original: arm9/ov001 @ 0x021640B4; symbol: func_ov001_021640b4; size: 0x60.
extern "C" int GameState_SetAngleAndPendingFromScriptParameters(FloatParameterView *parameter) {
    void *object = GameState_GetField3B0ObjectWithFlag4((GameState *)_ZN9GameState11GetInstanceEv());
    float value = ReadScriptParameterAsFloat(parameter);
    int input = ReadScriptParameterAsInteger((IntegerParameterView *)((unsigned char *)parameter + 8));
    int angle = (int)(4096.0f * value);
    unsigned short pending = (unsigned short)(input * 33);
    Object_SetAngleAndDeferredUpdateFlag(object, (unsigned int)angle, pending);
    return 1;
}
