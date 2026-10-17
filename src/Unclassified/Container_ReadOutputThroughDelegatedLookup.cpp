#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" bool FindAndInitializeABNKPayload(void*,void**);
// Original: arm9/main @ 0x020AFF00; symbol: func_020aff00; size: 0xC.
extern "C" bool Container_ReadOutputThroughDelegatedLookup(void* container,void** output){return FindAndInitializeABNKPayload(container,output);}
