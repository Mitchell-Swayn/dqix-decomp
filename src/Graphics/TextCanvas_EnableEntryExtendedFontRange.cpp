#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void DisplayLayout_SetPartFlags(void *,int,unsigned int);
// Original: arm9/main @ 0x020810A0; symbol: func_020810a0; size: 0x14.
    void TextCanvas_EnableEntryExtendedFontRange(unsigned char *p,int id){
        DisplayLayout_SetPartFlags(p+4,id,16);
    }
}
