#include <globaldefs.h>
extern "C" {
    unsigned char *WorldScriptArray_FindEntryByKey(void *,int);
// Original: arm9/main @ 0x0208DADC; symbol: func_0208dadc; size: 0x18.
    void *WorldScriptText_GetFinalText(void *p,int i){
        unsigned char *q=WorldScriptArray_FindEntryByKey(p,i);
        return q?*(void **)(q+20):0;
    }
}
