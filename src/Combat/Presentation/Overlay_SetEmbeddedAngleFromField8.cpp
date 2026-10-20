#include <globaldefs.h>
ARM
extern "C" unsigned BattleScene_GetActiveInstance();
extern "C" void* BattleScene_GetCamera(unsigned char*);
extern "C" void Camera_SetProjectionAngle(void*, unsigned);
// Original: arm9/ov025 @ 0x021E8510; symbol: func_ov025_021e8510; size: 0x38.
extern "C" int Overlay_SetEmbeddedAngleFromField8(unsigned char* p) {
    unsigned control = BattleScene_GetActiveInstance();
    if (control == 0) return 1;
    void* embedded = BattleScene_GetCamera((unsigned char*)control);
    if (embedded == 0) return 1;
    Camera_SetProjectionAngle(embedded, *(unsigned*)(p + 8));
    return 1;
}
