#include <globaldefs.h>
extern "C" {
    short *DisplayLayout_FindGroupById(void *);
    void DisplayLayout_SetPartFlags(void *,int,int);
// Original: arm9/main @ 0x02080608; symbol: func_02080608; size: 0x54.
    void TextCanvas_DisableGroupEntryNavigation(unsigned char *p){
        short *q=DisplayLayout_FindGroupById(p+12);
if(!q)return;
        for(unsigned char i=0;i<((unsigned char *)q)[19];i++)DisplayLayout_SetPartFlags(p+4,(*(short **)q)[i],2);
    }
}
