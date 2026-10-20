#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void TextCache_Reset(void*);
// Original: arm9/main @ 0x0203BD78; symbol: func_0203bd78; size: 0x10.
extern "C" void Graphics_ResetTransferRecordQueue(unsigned char* p){TextCache_Reset(p+16);}
