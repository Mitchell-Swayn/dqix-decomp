#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void DisplayLayout_SetPartFlags(void *,int,unsigned int);
// Original: arm9/main @ 0x02080B2C; symbol: func_02080b2c; size: 0x14.
    void TextCanvas_HideEntry(unsigned char *p,int id){
        DisplayLayout_SetPartFlags(p+4,id,1);
    }
}
