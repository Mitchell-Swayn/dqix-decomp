#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    unsigned int TestPackedBitForIndexZeroThrough204(void *,const void *,int);
// Original: arm9/main @ 0x02096088; symbol: func_02096088; size: 0x14.
    unsigned int TestOwnerPackedBitInEmbeddedBuffer(unsigned char *p,int id){
        return TestPackedBitForIndexZeroThrough204(p,p+132,id);
    }
}
