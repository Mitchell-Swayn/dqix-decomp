#include <globaldefs.h>
ARM
extern "C" void* Zone3D_GetMainInstance(void);
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" void _ZN6Zone3D10SwitchZoneEt(void*, unsigned int, unsigned int);
// Original: arm9/ov001 @ 0x021622A0; symbol: func_ov001_021622a0; size: 0x30.
extern "C" int Zone3D_SwitchZoneFromScriptParameter(void* parameter) { void* zone = Zone3D_GetMainInstance(); int id = Script_ReadParameterAsInteger(parameter); _ZN6Zone3D10SwitchZoneEt(zone, id, 0); return 1; }
