#include <globaldefs.h>
extern "C" {
    void ClearSelectedBufferUsingFormatSizeTable(void *,int);
// Original: arm9/main @ 0x0205D1E0; symbol: func_0205d1e0; size: 0x48.
    void ClearEachIndexedEntryResource(unsigned char *p){
        if(!*(char **)(p+0x98))return;
        for(unsigned char i=0;i<p[0xb2];i++)ClearSelectedBufferUsingFormatSizeTable(*(char **)(p+0x98)+i*32,0);
    }
}
