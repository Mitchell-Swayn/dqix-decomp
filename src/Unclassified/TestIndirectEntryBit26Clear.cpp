#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020687F8; symbol: func_020687f8; size: 0x2C.
    bool TestIndirectEntryBit26Clear(void *p,unsigned char *q){
        unsigned char *entry=*(unsigned char **)(q+32);
        if(!entry)return false;
        return ((*(unsigned int *)(entry+8)<<5)>>31)==0;
    }
}
