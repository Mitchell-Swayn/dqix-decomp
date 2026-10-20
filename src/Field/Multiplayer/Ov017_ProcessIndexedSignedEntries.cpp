#include <globaldefs.h>
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
extern "C" void GameState_QueuePartyMemberFieldUpdate(int);
// Original: arm9/ov017 @ 0x021D0DBC; symbol: func_ov017_021d0dbc; size: 0x44.
extern "C" void Ov017_ProcessIndexedSignedEntries(void) {
    Network_GetCommandRecordPool();
    void *state = _ZN9GameState11GetInstanceEv();
    char *list = (char *)GameState_GetIndexList(state);
    unsigned char count = *(unsigned char *)(list + 0xf7c);
    unsigned char i = 0;
    while (i < count) {
        GameState_QueuePartyMemberFieldUpdate(*(signed char *)(list + 0xf78 + i));
        i++;
    }
}
