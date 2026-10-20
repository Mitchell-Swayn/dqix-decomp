#pragma optimization_level 4
#include <globaldefs.h>
extern "C" {
    struct Bits{
        unsigned char a:1,b:1,c:6;
    };
// Original: arm9/main @ 0x02048004; symbol: func_02048004; size: 0x7C.
    void ZoneContainerRenderPart_ShareFrameAndAnimationResources(unsigned char *s,unsigned char *p){
        *(unsigned short *)(p+6)=*(unsigned short *)(s+6);
        *(int *)(p+8)=*(int *)(s+8);
        *(int *)(p+12)=*(int *)(s+12);
        *(int *)(p+16)=*(int *)(s+16);
        *(int *)(p+20)=*(int *)(s+20);
        *(int *)(p+24)=*(int *)(s+24);
        *(unsigned short *)(p+4)=*(unsigned short *)(s+4);
        ((Bits *)(p+132))->b=((Bits *)(s+132))->b;
        ((Bits *)(p+132))->a=((Bits *)(s+132))->a;
    }
}
