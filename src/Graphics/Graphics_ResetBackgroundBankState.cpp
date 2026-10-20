#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void Graphics_ClearBackgroundStateBlocks(void*);
// Original: arm9/main @ 0x0203B66C; symbol: func_0203b66c; size: 0xC.
extern "C" void Graphics_ResetBackgroundBankState(void* object){Graphics_ClearBackgroundStateBlocks(object);}
