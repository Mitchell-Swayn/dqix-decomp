#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" char *_ZN9GameState15GetGrottoStructEv(void *);
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void _ZN6Zone3D29ResetGrottoStateOutsideGrottoEv(void);
// Original: arm9/ov017 @ 0x021CFD2C; symbol: Grotto_CopySourceFlagAndResetOutsideGrotto; size: 0x30.
// Copies the source byte +4 to the GameState grotto byte +4 as a boolean, then resets grotto state outside a grotto.
extern "C" void Grotto_CopySourceFlagAndResetOutsideGrotto(void *unused, const unsigned char *source) {
    char *grotto = _ZN9GameState15GetGrottoStructEv(_ZN9GameState11GetInstanceEv());
    grotto[4] = source[4] != 0;
    Zone3D_GetMainInstance();
    _ZN6Zone3D29ResetGrottoStateOutsideGrottoEv();
}
