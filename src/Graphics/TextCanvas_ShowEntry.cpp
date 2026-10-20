#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void DisplayLayout_ClearPartFlags(void *,int,unsigned int);
// Original: arm9/main @ 0x02080B40; symbol: func_02080b40; size: 0x14.
    void TextCanvas_ShowEntry(unsigned char *p,int id){
        DisplayLayout_ClearPartFlags(p+4,id,1);
    }
}
