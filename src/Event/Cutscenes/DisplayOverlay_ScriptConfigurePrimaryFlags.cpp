#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" void DisplayOverlay_ConfigureGlobalState(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov001 @ 0x02162488; symbol: func_ov001_02162488; size: 0x20.
extern "C" int DisplayOverlay_ScriptConfigurePrimaryFlags(void* parameter) { int value = Script_ReadParameterAsInteger(parameter); DisplayOverlay_ConfigureGlobalState(value, 0, 1, 0); return 1; }
