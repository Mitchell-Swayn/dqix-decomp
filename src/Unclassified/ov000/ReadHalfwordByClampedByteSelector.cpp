#include <globaldefs.h>
ARM
extern "C" {
}
// Original: arm9/ov000 @ 0x0215FFA0; symbol: func_ov000_0215ffa0; size: 0x24.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" int ReadHalfwordByClampedByteSelector(char* p) {
    int i;
    unsigned n=(unsigned char)p[0x17];
    i=n-1;
    if(n>3)i=2;
    if(n==0)i=0;
    return ((short*)(p+14))[i];
}
