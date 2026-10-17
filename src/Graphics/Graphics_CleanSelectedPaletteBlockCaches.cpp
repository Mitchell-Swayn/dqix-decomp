#include <globaldefs.h>
#include <System/Cache.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0204AB4C; symbol: func_0204ab4c; size: 0x80.
    void Graphics_CleanSelectedPaletteBlockCaches(unsigned char *p,unsigned char *data){
        unsigned int len;
        memcpy(&len,data+8,4);
        unsigned short value=*(unsigned short *)(p+2);
        if(value==65535){
            CleanInvalidateCacheRange(data+12,len);
            return;
        }unsigned char mask=value;
        for(int i=0;i<16;i++){
            if(mask&1)CleanInvalidateCacheRange(data+12+i*32,32);
            mask>>=1;
        }
    }
}
