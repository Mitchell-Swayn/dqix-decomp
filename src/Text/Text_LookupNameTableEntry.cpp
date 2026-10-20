#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void *Text_BinarySearchNameTableEntry(void *,int);
// Original: arm9/main @ 0x020E5294; symbol: func_020e5294; size: 0xC.
    void *Text_LookupNameTableEntry(void *p,int id){
        return Text_BinarySearchNameTableEntry(p,id);
    }
}
