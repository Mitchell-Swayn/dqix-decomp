#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02068954; symbol: func_02068954; size: 0x2C.
    bool Object_TestNestedOffset10Word8Bit27Clear(void *p,unsigned char *q){
        unsigned char *entry=*(unsigned char **)(q+16);
        if(!entry)return false;
        return ((*(unsigned int *)(entry+8)<<4)>>31)==0;
    }
}
