#include <globaldefs.h>
ARM
struct Record {
    unsigned id:9;
    unsigned active:1;
    unsigned inherited:1;
    unsigned mode:3;
    unsigned reserved:2;
    unsigned special:1;
    unsigned tail:15;
    unsigned payload[3];
};
struct ActiveRecords {
    unsigned char count;
    unsigned char padding[3];
    Record entries[8];
};
struct PackedEntryStateOwner;
extern "C" {
void* memcpy(void*, const void*, unsigned);
void* GameState_GetSerializedProgressState();
void Script_SetPackedEntryStateAndNotifyPeers(PackedEntryStateOwner*, int, int);
}
// Inserts a sixteen-byte record into the counted, ID-ordered active list.
// The binary search rejects an equal midpoint; its boundary placement is preserved.
// Original: arm9/main @ 0x020962F4; symbol: func_020962f4; size: 0x168.
extern "C" int Quest_InsertActiveRecordInIdOrder(unsigned char* object, Record record)
{
    ActiveRecords* list = (ActiveRecords*)object;
    if (list->count >= 8) return 0;
    Record previous[8];
    if (list->count == 0) {
        memcpy(list->entries, &record, sizeof(Record));
    } else {
        memcpy(previous, list->entries, sizeof(previous));
        unsigned char lower = 0;
        unsigned char upper = list->count - 1;
        while (upper - lower > 1) {
            unsigned char middle = (upper + lower) / 2;
            if (record.id == list->entries[middle].id) return 0;
            if (list->entries[middle].id < record.id) lower = middle;
            else if (list->entries[middle].id > record.id) upper = middle;
        }
        if (list->entries[lower].id > record.id) {
            // Keep the lower bound as the insertion position.
        } else if (list->entries[upper].id < record.id) {
            lower = upper + 1;
        } else {
            lower = upper;
        }
        if (lower < list->count) {
            memcpy(&list->entries[lower + 1], &previous[lower],
                   (list->count - lower) * sizeof(Record));
        }
        memcpy(&list->entries[lower], &record, sizeof(Record));
    }
    Script_SetPackedEntryStateAndNotifyPeers(
        (PackedEntryStateOwner*)GameState_GetSerializedProgressState(), record.id, 2);
    list->count++;
    return 1;
}
