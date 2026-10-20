#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(void* state);
extern "C" unsigned Camera_GetObjectFlags(void* value);
extern "C" void Camera_UpdateRenderView(void* state);
extern "C" void Camera_UpdateRenderViewAndConditionalTargetMatrix(void* state);
// Original: arm9/ov017 @ 0x021959EC; symbol: func_ov017_021959ec; size: 0x34.
extern "C" void Camera_UpdateFromGameStateFlags(void) {
    void* state = GameState_ReadUnknownB0(_ZN9GameState11GetInstanceEv());
    if (state == 0) return;
    if (Camera_GetObjectFlags(state) & 8)
        Camera_UpdateRenderViewAndConditionalTargetMatrix(state);
    else
        Camera_UpdateRenderView(state);
}
