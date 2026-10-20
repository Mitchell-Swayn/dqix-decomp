#include <globaldefs.h>
ARM
extern "C" void WfcUtility_ReadSystemInformationBackInput(void);
extern "C" void WfcUtility_RunSystemInformationInputHook(void);
extern "C" void System_ResolveGroup7AndInstallCallbackWhenSharedByteZero(void);
// Original: arm9/ov031 @ 0x02228F1C; symbol: HandleInputBit2AndInstallCallback7; size: 0x14.
// Handles input mask 2, then when the shared signed byte is zero selects 7 and installs the next callback.
extern "C" void WfcUtility_UpdateSystemInformationScreen(void) { WfcUtility_ReadSystemInformationBackInput(); WfcUtility_RunSystemInformationInputHook(); System_ResolveGroup7AndInstallCallbackWhenSharedByteZero(); }
