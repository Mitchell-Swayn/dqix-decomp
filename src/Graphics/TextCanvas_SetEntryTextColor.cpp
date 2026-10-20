#include <globaldefs.h>
extern "C" {
    unsigned char *DisplayLayout_FindPartById(char *,int);
// Original: arm9/main @ 0x02080CC0; symbol: func_02080cc0; size: 0x2C.
    void TextCanvas_SetEntryTextColor(char *p,int id,unsigned int v){
        unsigned char *q=DisplayLayout_FindPartById(p+4,id);
        if(q)q[19]=(q[19]&~240)|((v<<28)>>24);
    }
}
