#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" void DispatchFourArgumentsUsingGlobalOwner(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov001 @ 0x02162488; symbol: func_ov001_02162488; size: 0x20.
extern "C" int func_ov001_02162488(void* parameter) { int value = ReadScriptParameterAsInteger(parameter); DispatchFourArgumentsUsingGlobalOwner(value, 0, 1, 0); return 1; }
