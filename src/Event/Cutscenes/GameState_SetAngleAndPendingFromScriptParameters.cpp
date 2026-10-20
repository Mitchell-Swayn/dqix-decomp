#include <globaldefs.h>
ARM
struct FloatParameterView;
struct IntegerParameterView;
struct GameState;
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetFieldOrbitCamera(GameState *);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView *parameter);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" void Camera_SetProjectionAngleTransition(void *object, unsigned angle, int pending);
// Original: arm9/ov001 @ 0x021640B4; symbol: func_ov001_021640b4; size: 0x60.
extern "C" int GameState_SetAngleAndPendingFromScriptParameters(FloatParameterView *parameter) {
    void *object = GameState_GetFieldOrbitCamera((GameState *)_ZN9GameState11GetInstanceEv());
    float value = Script_ReadParameterAsFloat(parameter);
    int input = Script_ReadParameterAsInteger((IntegerParameterView *)((unsigned char *)parameter + 8));
    int angle = (int)(4096.0f * value);
    unsigned short pending = (unsigned short)(input * 33);
    Camera_SetProjectionAngleTransition(object, (unsigned int)angle, pending);
    return 1;
}
