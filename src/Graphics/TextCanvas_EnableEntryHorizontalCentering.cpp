#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void DisplayLayout_SetPartFlags(void *,int,unsigned int);
// Original: arm9/main @ 0x0208108C; symbol: func_0208108c; size: 0x14.
    void TextCanvas_EnableEntryHorizontalCentering(unsigned char *p,int id){
        DisplayLayout_SetPartFlags(p+4,id,8);
    }
}
