#include <globaldefs.h>
ARM
// Original: arm9/ov001:0215f968; Reads the GameState angle target and sets cached trig state from an integer or float script parameter scaled by 4096.
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(void*);
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" float Script_ReadParameterAsFloat(void*);
extern "C" unsigned int _fmul(unsigned int, float);
extern "C" int _ffix(unsigned int);
extern "C" void Camera_SetProjectionAngle(void*, unsigned);
extern "C" int GameState_SetAngleFromIntegerOrFloatParameter(void* parameter) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* angleState = GameState_ReadUnknownB0(state);
    if (*(int*)parameter == 0) {
        int angle = Script_ReadParameterAsInteger(parameter);
        angle <<= 12;
        Camera_SetProjectionAngle(angleState, (unsigned)angle);
    } else if (*(int*)parameter == 1) {
        float value = Script_ReadParameterAsFloat(parameter);
        unsigned scaled = _fmul(0x45800000, value);
        Camera_SetProjectionAngle(angleState, (unsigned)_ffix(scaled));
    }
    return 1;
}
