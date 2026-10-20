#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x0215A718; symbol: func_ov001_0215a718; size: 0x1C.
extern "C" unsigned int Protection_InvokeCallbackAndReturnConfigurationScriptToken(void (*callback)(void)) { if (callback) callback(); return 0x001befcb; }
