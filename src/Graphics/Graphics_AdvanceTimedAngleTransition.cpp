#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void Camera_SetProjectionAngle(void*,unsigned);
// Original data: arm9/main @ 0x2104300; symbol: data_02104300.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned GraphicsAdvanceTimedAngleTransition_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x0202F0E0; symbol: func_0202f0e0; size: 0xC4.
extern "C" void Graphics_AdvanceTimedAngleTransition(char *self) {
    unsigned delta;
    int current;
    if (!*(unsigned*)(self + 0x1f4)) return;
    delta = _ZNK9GameState21GetEffectiveDeltaTimeEv(_ZN9GameState11GetInstanceEv());
    current = *(int*)(self + 0x58);
    int angle;
    if (delta >= *(unsigned*)(self + 0x1f4)) {
        *(unsigned*)(self + 0x1f4) = 0;
        angle = *(int*)(self + 0x1f0);
    } else {
        float start = (float)current;
        float difference = (float)(*(int*)(self + 0x1f0) - current);
        angle = (int)(start + difference * ((float)delta / (float)*(unsigned*)(self + 0x1f4)));
        *(unsigned*)(self + 0x1f4) -= delta;
        ++GraphicsAdvanceTimedAngleTransition_UnknownRoleZeroInitializedStorage;
    }
    Camera_SetProjectionAngle(self,angle);
}
