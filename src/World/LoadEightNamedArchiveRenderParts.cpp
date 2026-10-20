#include <globaldefs.h>
#include <World/Zone3DContainers.h>
#include <Filesystem/NarcHandle.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
ARM
extern "C" {
extern char LoadEightNamedArchiveRenderParts_FormatARCWinDSpr[];
void ZoneContainerRenderPart_LoadSerializedFramesAndAnimations(ZoneContainerRenderPart *,const void *,SafeAllocator *);
// Original: arm9/main @ 0x0202F310; symbol: func_0202f310; size: 0x70.
void LoadEightNamedArchiveRenderParts(ZoneContainerRenderPart *parts,SafeAllocator *allocator) {
    char path[40];
    for(int i=0;i<8;i++) {
        sprintf(path,LoadEightNamedArchiveRenderParts_FormatARCWinDSpr,i);
        const void *data=GetFileFromNARCInMemory(path);
        parts->Reset();ZoneContainerRenderPart_LoadSerializedFramesAndAnimations(parts,data,allocator);parts++;
    }
}
}
