#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020E2B50; symbol: func_020e2b50; size: 0x28.
    void Graphics_WriteMainObjectWindowMask(unsigned int value,int flag){
        volatile unsigned short *p=(volatile unsigned short *)0x0400004a;
        unsigned int old=*p;
        old&=~0x3f;
        old|=value;
        if(flag)old|=0x20;
        *p=old;
    }
}
