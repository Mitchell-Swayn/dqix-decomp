#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void ClearMaskedFlagsAtOffset2A(void *,int,unsigned int);
// Original: arm9/main @ 0x02080B40; symbol: func_02080b40; size: 0x14.
    void Object_ApplyModeOneToSelectedPartGroup(unsigned char *p,int id){
        ClearMaskedFlagsAtOffset2A(p+4,id,1);
    }
}
