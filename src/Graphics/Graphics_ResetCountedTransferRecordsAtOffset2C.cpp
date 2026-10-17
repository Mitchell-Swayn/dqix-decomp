#include <globaldefs.h>
extern "C" {
    void ClearSelectedBufferUsingFormatSizeTable(void *,int);
// Original: arm9/main @ 0x0207FCB8; symbol: func_0207fcb8; size: 0x48.
    void Graphics_ResetCountedTransferRecordsAtOffset2C(unsigned char *p){
        if(!*(char **)(p+44))return;
        for(unsigned char i=0;i<p[56];i++)ClearSelectedBufferUsingFormatSizeTable(*(char **)(p+44)+i*32,0);
    }
}
