#include <globaldefs.h>
ARM
extern "C" bool GameState_TestProtagonistIndexMatchesStoredByte(signed char* p);
extern "C" int OverlayLoader_GetSecondarySelectionOrMinusOne();
extern "C" void BattleScene_ResetCommandSelectionAndRestoreFlags(char* state);
// Original: arm9/ov000 @ 0x0216377C; symbol: func_ov000_0216377c; size: 0x4C.
extern "C" void GameState_UpdateStoredProtagonistIndex(char* self, unsigned char index) {
    char* state = *(char**)(self + 0x2A0);
    if (state == 0) return;
    (*(char**)(self + 0x2A0))[0x2A] = index;
    if (GameState_TestProtagonistIndexMatchesStoredByte((signed char*)*(char**)(self + 0x2A0))) {
        unsigned* flags = (unsigned*)(self + 0x55F4);
        *flags |= 0x40000000;
    }
    if (OverlayLoader_GetSecondarySelectionOrMinusOne() != 3) return;
    BattleScene_ResetCommandSelectionAndRestoreFlags(self);
}
