#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void RelocateTablePointerAndEntryOffsets(void *);
// Original: arm9/main @ 0x020B0094; symbol: func_020b0094; size: 0x10.
    void ResourceRecord_InitializeEmbeddedOffset8State(unsigned char *p){
        RelocateTablePointerAndEntryOffsets(p+8);
    }
}
