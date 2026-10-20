#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void DisplayLayout_ClearPartFlags(void*,int,unsigned);
// Original: arm9/main @ 0x020806C4; symbol: func_020806c4; size: 0x14.
extern "C" void TextCanvas_EnableEntryNavigation(unsigned char* p,int key){DisplayLayout_ClearPartFlags(p+4,key,2);}
