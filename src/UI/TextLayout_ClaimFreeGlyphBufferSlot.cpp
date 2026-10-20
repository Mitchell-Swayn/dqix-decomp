#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02042A90; symbol: func_02042a90; size: 0x64.
    int TextLayout_ClaimFreeGlyphBufferSlot(void *p,unsigned char *bits,unsigned int len){
        for(unsigned int i=0;i<len;i++){
            unsigned char value=*bits;
            for(int b=0;b<8;b++){
                unsigned char mask=1<<b;
                if(!(value&mask)){
                    *bits|=mask;
                    return b+i*8;
                }
            }bits++;
        }return -1;
    }
}
