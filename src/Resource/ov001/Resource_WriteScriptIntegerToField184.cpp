#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance(void);
extern "C" int ReadScriptParameterAsInteger(void*);
// Original: arm9/ov001 @ 0x021631A4; symbol: func_ov001_021631a4; size: 0x2C.
extern "C" int Resource_WriteScriptIntegerToField184(void* parameter) { void* resources = GameResources_GetInstance(); void* object = *(void**)((char*)resources + 0x3734); int value = ReadScriptParameterAsInteger(parameter); *(unsigned short*)((char*)object + 0x184) = value; return 1; }
