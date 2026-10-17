#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    extern unsigned char data_02102be0[];
    extern unsigned char data_02101980[];
    bool ResolveEntryWhenPresentAndEnabledBitsSet(void *,void *,int);
// Original: arm9/main @ 0x0202DCB4; symbol: func_0202dcb4; size: 0x20.
    bool ReadEnabledGlobalIndexedEntry(int i){
        return ResolveEntryWhenPresentAndEnabledBitsSet(data_02102be0,data_02101980,i);
    }
}
