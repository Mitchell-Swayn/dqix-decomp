#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(void* state);
extern "C" void _ZN8Vector3iaSERKS_(void* self, const void* other);
extern "C" void* ReadOverlayControlSecondWord(void);
// Original: arm9/ov025 @ 0x021E5A2C; symbol: func_ov025_021e5a2c; size: 0x40.
extern "C" int GameState_SetVectorFromParameterAndMarkOverlay(void* parameter) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* target = GameState_ReadUnknownB0(state);
    if (target != 0)
        _ZN8Vector3iaSERKS_((char*)target + 4, (char*)parameter + 8);
    void* overlay = ReadOverlayControlSecondWord();
    if (overlay != 0)
        *((unsigned char*)overlay + 0x6fd5) = 1;
    return 1;
}
