#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void ResetZoneStateAndClearThreeWords(void*);
// Original: arm9/main @ 0x0207CC0C; symbol: func_0207cc0c; size: 0xC.
extern "C" void Object_InitializeKeyResourceStateWrapper(void* object){ResetZoneStateAndClearThreeWords(object);}
