#include <globaldefs.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020C00B8; symbol: func_020c00b8; size: 0x10.
    CBool Object_InvokeNitroVM_FinishRead(unsigned char *p){
        return NitroVM_FinishRead((NitroVM *)(p+92));
    }
}
