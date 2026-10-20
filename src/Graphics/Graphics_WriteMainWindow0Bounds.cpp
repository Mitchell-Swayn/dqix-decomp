#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020E2A54; symbol: func_020e2a54; size: 0x34.
    void Graphics_WriteMainWindow0Bounds(unsigned int a,unsigned int b,unsigned int c,unsigned int d){
        volatile unsigned short *p=(volatile unsigned short *)0x04000040;
        unsigned int ac=((a<<8)&0xff00)|(c&255);
        unsigned int bd=((b<<8)&0xff00)|(d&255);
        p[0]=ac;
        p[2]=bd;
    }
}
