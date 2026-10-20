#include <globaldefs.h>
extern "C" int Resource_FindActiveGraphicCacheEntryByName(void*, const char*);
extern "C" void Graphics_LoadRResourceFramesPaletteAndGroups(void*, char*, unsigned int, unsigned int);
extern "C" void Filesystem_LoadFormattedPathForNamesEndingInR(void*, char*, unsigned int);
extern "C" char* strcpy(char*, const char*);
struct ResourceRecord { char name[56]; int references; };
struct ResourceManager {
    unsigned int count;
    unsigned char activeCount;
    unsigned char useNameLookup;
    unsigned char pad6[2];
    ResourceRecord* records;
};
// Original: arm9/main @ 0x0204027C; symbol: Resource_FindOrLoadNamedRecord; size: 0x120.
// Reuses a named resource record or loads it into the first record with a negative reference count.
extern "C" ARM int Resource_FindOrLoadNamedRecord(ResourceManager* self, char* name, unsigned int resource, unsigned int flags, unsigned int extra) {
    if (self->records == 0) return -1;
    int index = -1;
    if (self->useNameLookup == 0) index = Resource_FindActiveGraphicCacheEntryByName(self, name);
    if (index > -1) {
        ++self->records[index].references;
        return index;
    }
    for (unsigned int i = 0; i < self->count; ++i) {
        if (self->records[i].references < 0) {
            index = i;
            break;
        }
    }
    if (index < 0) return -1;
    if (flags != 0)
        Graphics_LoadRResourceFramesPaletteAndGroups((unsigned char*)(self->records + index) + 0x10, name, resource, flags);
    else
        Filesystem_LoadFormattedPathForNamesEndingInR((unsigned char*)(self->records + index) + 0x10, name, resource);
    self->records[index].references = 0;
    strcpy(self->records[index].name, name);
    ++self->activeCount;
    return index;
}
