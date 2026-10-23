#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct ZoneContainerRenderPart;class SafeAllocator;
extern "C" void LoadEightNamedArchiveRenderParts(ZoneContainerRenderPart*,SafeAllocator*);
// Original: arm9/main @ 0x020440B8; symbol: func_020440b8; size: 0x14.
extern "C" void TextWindow_LoadFrameArchiveParts(unsigned char* p,SafeAllocator* allocator,const void* unusedArchive){LoadEightNamedArchiveRenderParts((ZoneContainerRenderPart*)(p+0x19e0),allocator);}
