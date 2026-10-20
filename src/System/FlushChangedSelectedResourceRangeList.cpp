#include <globaldefs.h>

#include "System/Cache.h"

struct RangeEntry {
    unsigned char unknown_0[8];
    unsigned length;
    const void* data;
};

struct RangeList {
    unsigned char unknown_0[4];
    unsigned short count;
    unsigned char unknown_6[2];
    RangeEntry* entries;
};

struct Group {
    unsigned char unknown_0[0x10];
    unsigned* elements;
};

struct Request {
    void* owner;
    unsigned char unknown_4[0x24];
    short valid;
    unsigned char unknown_2a[6];
    unsigned groupIndex;
    unsigned elementIndex;
    unsigned char unknown_38[0xc];
    unsigned prevGroupIndex;
    unsigned prevElementIndex;
};

extern "C" {
unsigned char* Resource_GetActiveGraphicCacheEntry(void* table, int index);
Group* ActorSpriteResource_GetAnimation(void* table, unsigned index);
RangeList* ActorSpriteResource_GetFrame(void* table, unsigned index);
}

// Flushes the data cache for every range of the requested element if the selection changed.
// Original: arm9/main @ 0x0203F2B0; symbol: func_0203f2b0; size: 0xA4.
extern "C" ARM void FlushChangedSelectedResourceRangeList(Request* req) {
    if (req->valid < 0) return;
    if (req->elementIndex == req->prevElementIndex && req->groupIndex == req->prevGroupIndex) return;
    unsigned char* owner = Resource_GetActiveGraphicCacheEntry(req->owner, req->valid);
    if (!owner) return;
    Group* group = ActorSpriteResource_GetAnimation(owner + 0x10, req->groupIndex);
    if (!group) return;
    RangeList* list = ActorSpriteResource_GetFrame(owner + 0x10, group->elements[req->elementIndex]);
    if (!list) return;
    RangeEntry* entry = list->entries;
    if (!entry) return;
    for (int i = 0; i < list->count; i++, entry++) {
        CleanInvalidateCacheRange(entry->data, entry->length);
    }
}
