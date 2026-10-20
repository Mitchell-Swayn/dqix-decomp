#include <globaldefs.h>
extern "C" {
    struct Bytes{
        unsigned char value[22];
    };
    struct R{
        Bytes bytes;
        unsigned char a,b;
    };
// Original: arm9/main @ 0x02082D38; symbol: func_02082d38; size: 0x34.
    void CharacterState_CopyAttributePercentages(R *out,const R *in){
        out->bytes=in->bytes;
        out->a=in->a;
        out->b=in->b;
    }
}
