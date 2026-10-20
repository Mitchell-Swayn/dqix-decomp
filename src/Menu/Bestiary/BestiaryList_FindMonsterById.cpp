#include <globaldefs.h>
#pragma always_inline on
#pragma opt_propagation off
struct BestiaryLookupView {
    unsigned unknown_00;
    unsigned count:12;
    unsigned flags:20;
    unsigned char* entries;
};
extern "C" int BestiaryEntry_GetMonsterId(int);
inline unsigned char* FindSortedBestiaryEntry(BestiaryLookupView* list, int monsterId, int (*getId)(int))
{
    unsigned char* entries = list->entries;
    if (!entries || !(unsigned)getId) return 0;
    unsigned count = list->count;
    if (!count) return 0;
    int low = 0;
    int high = count - 1;
    while (low <= high) {
        int middle = low + ((high - low + 1) >> 1);
        unsigned char* entry = entries + middle * 32;
        int key = getId((int)entry);
        if (key == monsterId) return entry;
        if (key > monsterId) high = middle - 1;
        else low = middle + 1;
    }
    return 0;
}
#pragma force_active on
// Original: arm9/main @ 0x02097430; symbol: func_02097430; size: 0x80.
// Finds a monster id in the sorted thirty-two-byte bestiary entries.
extern "C" ARM unsigned char* BestiaryList_FindMonsterById(void* listBytes, int monsterId)
{
    return FindSortedBestiaryEntry((BestiaryLookupView*)listBytes, monsterId, BestiaryEntry_GetMonsterId);
}
#pragma force_active off
