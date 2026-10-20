#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void*);
extern "C" void* BattleMenu_FindPartyCommandRecord(void*, int);
extern "C" void BattleMenu_UpdateMemberRowPositions(void*);
struct RecordFlags { unsigned char low:2; unsigned char bit2:1; unsigned char high:5; };
// Original: arm9/ov000 @ 0x02181364; symbol: func_ov000_02181364; size: 0x70.
extern "C" void GameState_ResetIndexedRecordsAndFinalize(void* table) {
    void* list = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    unsigned char count = *((unsigned char*)list + 0xf7c);
    for (unsigned char i = 0; i < count; ++i) {
        unsigned char index = *((unsigned char*)list + 0xf78 + i);
        unsigned char* record = (unsigned char*)BattleMenu_FindPartyCommandRecord(table, index);
        if (record != 0) {
            signed char offset = *(signed char*)(record + 0x18);
            *(record + offset + 0x10) = 0x64;
            ((RecordFlags*)(record + 0x24))->bit2 = 0;
        }
    }
    BattleMenu_UpdateMemberRowPositions(table);
}
