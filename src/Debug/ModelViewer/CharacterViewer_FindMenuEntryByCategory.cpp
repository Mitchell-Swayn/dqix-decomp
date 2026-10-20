#include <globaldefs.h>
ARM
struct RecordArray;
struct Record;
extern "C" Record *CharacterViewer_GetMenuCatalogEntry(RecordArray *, int);

// Original: arm9/ov015 @ 0x02193160; symbol: func_ov015_02193160; size: 0x54.
extern "C" Record *CharacterViewer_FindMenuEntryByCategory(void *object, unsigned char value, int *index) {
    int current = *index;
    while (current < *(int *)((unsigned char *)object + 0x44)) {
        Record *record = CharacterViewer_GetMenuCatalogEntry((RecordArray *)((unsigned char *)object + 0x3c), current);
        if (record == 0) break;
        if (value == *((unsigned char *)record + 0xa)) {
            *index = current;
            return record;
        }
        ++current;
    }
    return 0;
}
