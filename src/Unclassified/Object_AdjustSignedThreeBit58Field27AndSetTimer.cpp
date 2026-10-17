#include <globaldefs.h>
extern "C" {
    void ClearField14Flag2000000AndField58Flag38000000AndBytes77And9A(void *);
    struct Bits{
        unsigned int pad:27;
        int value:3;
        unsigned int high:2;
    };
// Original: arm9/main @ 0x02087F78; symbol: func_02087f78; size: 0x78.
    int Object_AdjustSignedThreeBit58Field27AndSetTimer(unsigned char *p,int delta){
        Bits *b=(Bits *)(p+88);
        int value=delta+b->value;
        if(value>2)value=2;
        if(value<-2)value=-2;
        if(!value){
            ClearField14Flag2000000AndField58Flag38000000AndBytes77And9A(p);
            return 0;
        }b->value=value;
        p[119]=5;
        p[154]=0;
        *(int *)(p+20)|=0x2000000;
        return b->value;
    }
}
