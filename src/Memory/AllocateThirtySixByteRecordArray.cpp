#pragma optimization_level 4
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original: arm9/main @ 0x020277C4; symbol: func_020277c4; size: 0x30.
    void AllocateThirtySixByteRecordArray(int *p,int count,SafeAllocator *alloc){
        p[8]=(int)alloc->Allocate(count*36);
        p[9]=0;
        p[10]=count;
    }
}
