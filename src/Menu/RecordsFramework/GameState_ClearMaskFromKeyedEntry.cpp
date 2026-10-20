#include <globaldefs.h>
ARM
struct State;
extern "C" void *Menu_GetDisplayRecordRegistry(State *self);
extern "C" void *MenuRecordList_LocateByKey(void **head, unsigned short value);
// Original: arm9/ov023 @ 0x021F6600; symbol: GameState_ClearMaskFromKeyedEntry; size: 0x30.
// Resolves the keyed state entry and clears the requested bits in its byte at +0xc.
extern "C" void GameState_ClearMaskFromKeyedEntry(State *self, unsigned short value, unsigned char mask) {
    void *head = Menu_GetDisplayRecordRegistry(self);
    unsigned char *node = (unsigned char *)MenuRecordList_LocateByKey((void **)head, value);
    if (node != 0) node[0xc] = node[0xc] & ~mask;
}
