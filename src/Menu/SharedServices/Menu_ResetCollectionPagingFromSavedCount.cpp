#include <globaldefs.h>
ARM
struct State;
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Menu_QueueScriptEntry(State* self, unsigned value);
extern "C" void* Menu_GetDisplayRecordRegistry(State* self);
extern "C" void *MenuRecordList_LocateByKey(void **head, unsigned short value);
extern "C" unsigned MenuRecord_GetType(void*);
struct Buffer { unsigned words[4]; unsigned count : 9; unsigned flags : 23; unsigned tail[39]; };
// Original: arm9/ov004 @ 0x02156760; symbol: func_ov004_02156760; size: 0x98.
extern "C" int Menu_ResetCollectionPagingFromSavedCount(State *self) {
    char *entry = (char*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self), 3);
    if (!entry) return 0;
    if (MenuRecord_GetType(entry) != 7) return 0;
    Buffer buffer;
    GameState_CopyStatisticsRecord(&buffer);
    unsigned pages;
    unsigned count = buffer.count;
    pages = count / 12;
    if (count % 12) pages++;
    if (pages) {
        *(short*)(entry + 0x5c) = 0;
        *(short*)(entry + 0x5e) = pages;
        return 0;
    } else {
        Menu_QueueScriptEntry(self, 0x66);
    }
    return 0;
}
