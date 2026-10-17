#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
#pragma optimization_level 4
extern "C" {
    void func_02047b40(void *,const void *,SafeAllocator *);
// Original: arm9/main @ 0x02047B30; symbol: func_02047b30; size: 0x10.
    void ZoneRenderPart_LoadSerializedDataWithAllocator(void *p,const void *data,int unused,SafeAllocator *alloc){
        func_02047b40(p,data,alloc);
    }
}
