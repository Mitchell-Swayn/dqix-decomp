#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *GameState_GetObjectWithFlag100(void *, int);
extern "C" unsigned char *GameObject_GetLinkedIndexedState(void *);
struct Record;
extern "C" Record *BattleMenu_FindPartyCommandRecord(void *, int);

// Original: arm9/ov000 @ 0x02175FC8; symbol: GameState_UpdateFourRecordsFromObjects; size: 0x70.
// Scans four keyed records, propagates object flag bit 2, and copies the low byte of object field 0x94C when available.
extern "C" void GameState_UpdateFourRecordsFromObjects(void *collection) {
    Record *record;
    int i = 0;
    for (; i < 4; ++i) {
        record = BattleMenu_FindPartyCommandRecord(collection, i);
        if (record == 0) continue;
        void *gameState = _ZN9GameState11GetInstanceEv();
        void *object = GameState_GetObjectWithFlag100(gameState, *(int *)((unsigned char *)record + 0x4c));
        if (object == 0) continue;
        unsigned int *flags = *(unsigned int **)((unsigned char *)object + 0x130);
        if (*flags & 4)
            *(unsigned int *)((unsigned char *)record + 0x28) |= 4;
        unsigned char *field = GameObject_GetLinkedIndexedState(object);
        if (field != 0)
            *((unsigned char *)record + 0x443) = *(unsigned int *)(field + 0x94c);
    }
}
