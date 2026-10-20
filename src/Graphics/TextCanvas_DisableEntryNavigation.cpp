#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void DisplayLayout_SetPartFlags(void*,int,unsigned);
// Original: arm9/main @ 0x020806B0; symbol: func_020806b0; size: 0x14.
extern "C" void TextCanvas_DisableEntryNavigation(unsigned char* p,int key){DisplayLayout_SetPartFlags(p+4,key,2);}
