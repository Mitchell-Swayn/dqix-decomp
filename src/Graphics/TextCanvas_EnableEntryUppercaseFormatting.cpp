#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void DisplayLayout_SetPartFlags(void *,int,unsigned int);
// Original: arm9/main @ 0x020805F4; symbol: func_020805f4; size: 0x14.
    void TextCanvas_EnableEntryUppercaseFormatting(unsigned char *p,int id){
        DisplayLayout_SetPartFlags(p+4,id,64);
    }
}
