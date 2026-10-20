#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020E2AD8; symbol: func_020e2ad8; size: 0x28.
    void Graphics_WriteMainWindow1InsideMask(unsigned int value,int flag){
        volatile unsigned short *p=(volatile unsigned short *)0x04000048;
        unsigned int old=*p;
        old&=~0x3f00;
        old|=value<<8;
        if(flag)old|=0x2000;
        *p=old;
    }
}
