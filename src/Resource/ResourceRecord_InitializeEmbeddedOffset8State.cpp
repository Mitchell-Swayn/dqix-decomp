#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void NNSi_G2dUnpackUserExCellAttrBank(void *);
// Original: arm9/main @ 0x020B0094; symbol: func_020b0094; size: 0x10.
    void ResourceRecord_InitializeEmbeddedOffset8State(unsigned char *p){
        NNSi_G2dUnpackUserExCellAttrBank(p+8);
    }
}
