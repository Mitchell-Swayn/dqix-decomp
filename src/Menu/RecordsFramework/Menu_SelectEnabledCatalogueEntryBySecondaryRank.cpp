#include <globaldefs.h>
ARM
#pragma force_active on
namespace {
struct CatalogueEntry {
    unsigned int preceding[2];
    unsigned short unknown8, primaryRank, secondaryRank;
    unsigned char selected : 1;
    unsigned char enabled : 1;
    unsigned char category : 6;
    unsigned char group;
};
struct Catalogue { unsigned int unknown0; CatalogueEntry* entries; short count; };
}
// Original: arm9/ov023 @ 0x021E170C; symbol: func_ov023_021e170c; size: 0x108.
// Selects the lowest-ranked unselected entry satisfying the category/group filters; marks its selection bit.
extern "C" void* Menu_SelectEnabledCatalogueEntryBySecondaryRank(void* catalogue, unsigned int includeSpecial, unsigned int category, unsigned int group) {
    unsigned int bestRank = 0xffff;
    CatalogueEntry* entry;
    CatalogueEntry* selected = 0;
    CatalogueEntry* entries = ((Catalogue*)catalogue)->entries;
    short count = ((Catalogue*)catalogue)->count;
    int i = 0;
    for (; i < count; i = (short)(i + 1)) {
        entry = entries + i;
        if (!entry->selected && bestRank >= entry->secondaryRank && entry->enabled) {
            unsigned int rank = entry->secondaryRank;
            if (!includeSpecial) {
                int accepted = entry->category <= 7 ? 1 : 0;
                if (!accepted) continue;
            } else if ((int)category >= 0 && (int)group >= 0) {
                if (entry->group == group) {
                    if (category != entry->category) continue;
                } else continue;
            } else if ((int)category >= 0) {
                if (entry->category != category) continue;
            } else if ((int)group >= 0) {
                if (entry->group != group) continue;
            }
            bestRank = rank;
            selected = entry;
        }
    }
    if (selected) selected->selected = 1;
    return (void*)selected;
}
