#include <globaldefs.h>
ARM
struct Vector3fix;
extern "C" void* BattleScene_GetActiveInstance(void);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* GameState_ReadUnknownB0(void*);
extern "C" void Camera_StartEyeMovement(char*, const Vector3fix*, const Vector3fix*, int, int);
// Original: arm9/ov025 @ 0x021E72A8; symbol: func_ov025_021e72a8; size: 0x4C.
extern "C" int GameState_ApplyOverlayControlledVectorTransform(char* object) {
    void* control = BattleScene_GetActiveInstance();
    if (control) ((unsigned char*)control)[0x6000 + 0xfd5] = 1;
    void* state = _ZN9GameState11GetInstanceEv();
    char* transform = (char*)GameState_ReadUnknownB0(state);
    Camera_StartEyeMovement(transform, (Vector3fix*)(object + 8), *(Vector3fix**)(object + 0x14), *(int*)(object + 0x18), *(int*)(object + 0x1c));
    return 1;
}
