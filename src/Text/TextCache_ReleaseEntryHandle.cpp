#include <globaldefs.h>
extern "C" {
    void TextCache_ResetEntry(void *);
// Original: arm9/main @ 0x0203C54C; symbol: func_0203c54c; size: 0x5C.
    void TextCache_ReleaseEntryHandle(unsigned char *p,short *index){
        short i=*index;
        if(i<0)return;
        unsigned char *q=p+4+i*40;
        *index=-1;
        if(!q[36])return;
        q[36]--;
        if(q[36])return;
        TextCache_ResetEntry(q);
        (*(unsigned short *)(p+0x512))--;
    }
}
