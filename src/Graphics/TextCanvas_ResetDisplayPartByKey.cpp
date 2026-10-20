#include <globaldefs.h>
extern "C" {
    void *TextCanvas_FindDisplayPartByKey(void *,int,void *);
    void TextCanvas_ResetLayoutAndDisplayFlags(void *);
// Original: arm9/main @ 0x0207FDCC; symbol: func_0207fdcc; size: 0x24.
    void TextCanvas_ResetDisplayPartByKey(unsigned char *p,int value){
        void *q=*(void **)(p+48);
        if(!q)return;
        q=TextCanvas_FindDisplayPartByKey(p,value,q);
        if(!q)return;
        TextCanvas_ResetLayoutAndDisplayFlags(q);
    }
}
