#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void Ov031_ConfigureDisplayAfterContextReady(void);
// Original: arm9/ov031 @ 0x02234440; symbol: ConfigureMode3RecordsAndInstallCallback_02234440; size: 0x3C.
// Initializes two mode-3 records with tuples (1,1,8) and (0,0x15,8), then installs its callback. Address suffix temporarily disambiguates a same-module peer; naming remains pending refinement.
extern "C" void WfcUtility_StartTimedScreenFadeOut(void) {
    WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback((void*)Ov031_ConfigureDisplayAfterContextReady);
}
