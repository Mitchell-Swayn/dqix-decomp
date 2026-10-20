#include <globaldefs.h>
extern "C" {
    unsigned char *DisplayLayout_FindGroupById(char *,int);
    void DisplayLayout_SetPartFlags(char *,int,int);
// Original: arm9/main @ 0x02080B54; symbol: func_02080b54; size: 0x58.
    void TextCanvas_HideGroupEntries(char *p,int id){
        unsigned char *q=DisplayLayout_FindGroupById(p+12,id);
        if(!q)return;
        for(short i=0;i<q[19];i++)DisplayLayout_SetPartFlags(p+4,(*(short **)q)[i],1);
    }
}
