#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02029470; symbol: func_02029470; size: 0x2C.
    void Graphics_WritePackedPolygonAttributes(unsigned int a,unsigned int b,unsigned int c,unsigned int d,unsigned int e,unsigned int f){
        *(volatile unsigned int *)0x040004a4=a|(b<<4)|(c<<6)|f|(d<<24)|(e<<16);
    }
}
