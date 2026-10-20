#include <globaldefs.h>
extern "C" {
    void Graphics_ClearScreenBuffer(void *,int);
// Original: arm9/main @ 0x0207FCB8; symbol: func_0207fcb8; size: 0x48.
    void TextCanvas_ClearDisplayLayerBuffers(unsigned char *p){
        if(!*(char **)(p+44))return;
        for(unsigned char i=0;i<p[56];i++)Graphics_ClearScreenBuffer(*(char **)(p+44)+i*32,0);
    }
}
