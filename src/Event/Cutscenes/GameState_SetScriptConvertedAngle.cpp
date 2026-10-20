#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(void*);
extern "C" float Script_ReadParameterAsFloat(void*);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int);
extern "C" void Camera_SetRollAndStopTransition(void*, short);
// Original: arm9/ov001 @ 0x0215E0DC; symbol: GameState_SetScriptConvertedAngle; size: 0x70.
// Converts a script float to a 4096-scaled fixed-point angle, maps it by the 0x47 scale with rounding, normalizes it to 0..2π, then updates the game-state object halfword.
extern "C" int GameState_SetScriptConvertedAngle(void* parameter) {
    void* object = GameState_ReadUnknownB0(_ZN9GameState11GetInstanceEv());
    float degrees = Script_ReadParameterAsFloat(parameter);
    int fixed = (int)(degrees * 4096.0f);
    int angle = (int)(((long long)fixed * 71 + 0x800) >> 12);
    angle = _Z22fix32ReduceAngle0To2Pii(angle);
    Camera_SetRollAndStopTransition(object, (short)angle);
    return 1;
}
