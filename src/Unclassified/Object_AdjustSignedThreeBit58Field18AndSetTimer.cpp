#include <globaldefs.h>
extern "C" {
    void ClearField14Flag10000AndField58Flag1C0000AndBytes74And97(void *);
    struct Bits{
        unsigned int pad:18;
        int value:3;
        unsigned int high:11;
    };
// Original: arm9/main @ 0x02087D78; symbol: func_02087d78; size: 0x78.
    int Object_AdjustSignedThreeBit58Field18AndSetTimer(unsigned char *p,int delta){
        Bits *b=(Bits *)(p+88);
        int value=delta+b->value;
        if(value>2)value=2;
        if(value<-2)value=-2;
        if(!value){
            ClearField14Flag10000AndField58Flag1C0000AndBytes74And97(p);
            return 0;
        }b->value=value;
        p[116]=5;
        p[151]=0;
        *(int *)(p+20)|=0x10000;
        return b->value;
    }
}
