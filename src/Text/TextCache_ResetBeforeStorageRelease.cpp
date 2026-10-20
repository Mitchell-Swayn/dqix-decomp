#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void TextCache_Reset(void *);
// Original: arm9/main @ 0x0203C4C4; symbol: func_0203c4c4; size: 0xC.
    void TextCache_ResetBeforeStorageRelease(void *p){
        TextCache_Reset(p);
    }
}
