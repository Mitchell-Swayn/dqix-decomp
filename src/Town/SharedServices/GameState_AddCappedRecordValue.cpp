#include <globaldefs.h>
ARM
struct GameState; struct Entry;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState* state);
extern "C" Entry *ZoneState2754_FindPrimaryRecordByKey(void *,int);
extern "C" void Shop_RefreshGoldDisplay(void*);
// Original: arm9/ov003 @ 0x02175D78; symbol: func_ov003_02175d78; size: 0x7C.
extern "C" int GameState_AddCappedRecordValue(unsigned char *self) {
    GameState *state = (GameState*)_ZN9GameState11GetInstanceEv();
    char *record = (char*)ZoneState2754_FindPrimaryRecordByKey(self + 0x874, *(short*)(self + 0x103a));
    if (!record) return 0;
    char *list = (char*)GameState_GetIndexList(state);
    unsigned value = self[0x103c] * *(unsigned short*)(record + 0x1a);
    unsigned room = 9999999 - *(unsigned*)(list + 0xf6c);
    if (room < value) value = room;
    *(unsigned*)(list + 0xf6c) += value;
    Shop_RefreshGoldDisplay(self);
    return 1;
}
