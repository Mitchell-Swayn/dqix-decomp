#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" bool Graphics_FindAndUnpackAnimationBank(void*,void**);
// Original: arm9/main @ 0x020AFF00; symbol: func_020aff00; size: 0xC.
extern "C" bool NNS_G2dGetUnpackedAnimBank(void* container,void** output){return Graphics_FindAndUnpackAnimationBank(container,output);}
