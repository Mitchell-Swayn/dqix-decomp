#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void TextStream_UpdateTimedControlCodePlayback(void*);
// Original: arm9/main @ 0x020444D4; symbol: func_020444d4; size: 0xC.
extern "C" void TextWindow_UpdateMessageState(void* p){TextStream_UpdateTimedControlCodePlayback(p);}
