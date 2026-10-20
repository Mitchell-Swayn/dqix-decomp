#include <globaldefs.h>
ARM
extern "C" void FieldScreen_ReleaseOverlayThreeSession(void *);
extern "C" void GameState_RefreshPresentPartyCombatantFlags(void);
// Original: arm9/ov017 @ 0x021C168C; symbol: func_ov017_021c168c; size: 0x1C.
extern "C" void FieldScreen_CancelOverlayThreeSession(void *object) {
    FieldScreen_ReleaseOverlayThreeSession(object);
    *(unsigned char *)((unsigned char *)object + 1) = 1;
    GameState_RefreshPresentPartyCombatantFlags();
}
