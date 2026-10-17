#include <globaldefs.h>
extern "C" {
    bool TestLinkedWordFlagBitSeven(void *);
    bool TestIndirectComponentFlag100(void *);
    bool Object_TestNestedOffset138Word14Bit0(void *);
    bool ReadIndirectComponentByte56OrZero(void *);
// Original: arm9/main @ 0x02049A74; symbol: func_02049a74; size: 0x70.
    void Object_SetNestedFlag4WhenObjectStateAllows(unsigned char *p){
        if(!*(unsigned char **)(p+0x13c))return;
        if(TestLinkedWordFlagBitSeven(p))return;
        if(TestIndirectComponentFlag100(p))return;
        if(!(*(unsigned char **)(p+0x13c))[86])return;
        if(Object_TestNestedOffset138Word14Bit0(p))return;
        if(ReadIndirectComponentByte56OrZero(p)){
            unsigned char *q=*(unsigned char **)(p+0x13c);
            *(int *)(q+32)|=4;
        }
    }
}
