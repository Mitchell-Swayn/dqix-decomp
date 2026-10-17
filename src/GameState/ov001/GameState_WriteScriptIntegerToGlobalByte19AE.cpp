#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" int ReadScriptParameterAsInteger(void*);
// Original: arm9/ov001 @ 0x0215E938; symbol: func_ov001_0215e938; size: 0x28.
extern "C" int GameState_WriteScriptIntegerToGlobalByte19AE(void* parameter) { unsigned int base = ReadWordFieldAtOffset1C(); int value = ReadScriptParameterAsInteger(parameter); *((unsigned char*)((char*)base + 0x19ae)) = value; return 1; }
