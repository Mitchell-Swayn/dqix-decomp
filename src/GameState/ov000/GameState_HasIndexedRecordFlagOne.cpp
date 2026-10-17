#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" char* FindFourSlotRecordByIndex(void*, int);
// Original: arm9/ov000 @ 0x0217FE30; symbol: func_ov000_0217fe30; size: 0x80.
extern "C" bool GameState_HasIndexedRecordFlagOne(void* records) {
    bool found = false;
    char* list = (char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv());
    unsigned char count = *(unsigned char*)(list+0xf7c);
    for (unsigned char index=0; index<count; ++index) {
        char* record=FindFourSlotRecordByIndex(records, *(signed char*)(list+0xf78+index));
        if (record) found |= (*(unsigned char*)(record+0x24)&1)!=0;
    }
    return found;
}
