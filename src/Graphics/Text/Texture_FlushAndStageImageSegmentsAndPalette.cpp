#include <globaldefs.h>
#include "System/Cache.h"
#include "Graphics/VRAMStaging.h"
struct Image {unsigned unused;unsigned short count,pad;char* segments;unsigned bytes;void* data;};
struct Segment {unsigned a,b,length;void* data;};
struct Resource {char pad[0x10];unsigned a,b,c,count;void* palette;unsigned paletteOffset;};
struct Texture {unsigned id;char pad[0x24];short resourceID;char pad1[6];unsigned imageID,index;char pad2[12];unsigned previousImage,previousIndex,imageOffset;char pad3[8];short imageTask,paletteTask;};
extern "C" Resource* Resource_GetActiveGraphicCacheEntry(unsigned,int);
extern "C" char* ActorSpriteResource_GetAnimation(void*,unsigned);
extern "C" Image* ActorSpriteResource_GetFrame(void*,unsigned);
// Original: arm9/main @ 0x0203F430; symbol: func_0203f430; size: 0x10C.
extern "C" ARM void Texture_FlushAndStageImageSegmentsAndPalette(Texture* p){
    Resource* resource=Resource_GetActiveGraphicCacheEntry(p->id,p->resourceID);
    if(!resource)return;
    char* entry=ActorSpriteResource_GetAnimation((char*)resource+0x10,p->imageID);
    if(!entry)return;
    Image* image=ActorSpriteResource_GetFrame((char*)resource+0x10,(*(unsigned**)(entry+0x10))[p->index]);
    Segment* segments;
    if(image && (segments=(Segment*)image->segments)){
        for(int i=0;i<image->count;){CleanInvalidateCacheRange(segments->data,segments->length);++i;++segments;}
        CleanInvalidateCacheRange(resource->palette,resource->count<<1);
        if(image->count){CancelVRAMStagingOperation(p->imageTask);p->imageTask=StageMemoryToVRAM((VRAMSubregion)1,image->data,p->imageOffset,image->bytes,false,false);}
        CancelVRAMStagingOperation(p->paletteTask);
        p->paletteTask=StageMemoryToVRAM((VRAMSubregion)0,resource->palette,resource->paletteOffset,resource->count<<1,false,false);
        p->previousImage=p->imageID;p->previousIndex=p->index;
    }
}
