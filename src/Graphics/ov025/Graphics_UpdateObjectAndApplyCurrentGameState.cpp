#include <globaldefs.h>
ARM
extern "C" {
void* ReadOverlayControlSecondWord();
void* _ZN9GameState11GetInstanceEv();
void* GameState_ReadUnknownB0(void*);
void Object_SetHalfword7CAndClear1EC1EE(void*, int);
// Original: arm9/ov025 @ 0x021E7214; symbol: func_ov025_021e7214; size: 0x34.
int Graphics_UpdateObjectAndApplyCurrentGameState(void *p) {
    void *overlay = ReadOverlayControlSecondWord();
    if (overlay) *(unsigned char *)((char *)overlay + 0x6fd5) = 1;
    void *state = _ZN9GameState11GetInstanceEv();
    void *object = GameState_ReadUnknownB0(state);
    Object_SetHalfword7CAndClear1EC1EE(object, *(short *)((char *)p + 8));
    return 1;
}
}
