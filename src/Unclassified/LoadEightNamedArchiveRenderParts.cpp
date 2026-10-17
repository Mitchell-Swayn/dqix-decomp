#include <globaldefs.h>
#include <World/Zone3DContainers.h>
#include <Filesystem/NarcHandle.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
ARM
extern "C" {
extern char data_020ef7c4[];
void func_02047b40(ZoneContainerRenderPart *,const void *,SafeAllocator *);
// Original: arm9/main @ 0x0202F310; symbol: func_0202f310; size: 0x70.
void LoadEightNamedArchiveRenderParts(ZoneContainerRenderPart *parts,SafeAllocator *allocator) {
    char path[40];
    for(int i=0;i<8;i++) {
        sprintf(path,data_020ef7c4,i);
        const void *data=GetFileFromNARCInMemory(path);
        parts->Reset();func_02047b40(parts,data,allocator);parts++;
    }
}
}
