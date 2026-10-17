#include <globaldefs.h>
#include <System/LoadToVRAM.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020BBC2C; symbol: func_020bbc2c; size: 0xC.
    void Object_InvokeLoadToSubObjVRAM(const void *p,unsigned int offset,unsigned int len){
        LoadToSubObjVRAM(p,offset,len);
    }
}
