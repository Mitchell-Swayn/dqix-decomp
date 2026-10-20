#include <globaldefs.h>
ARM
extern "C" void *FieldBattle_GetEncounterRequest(void *);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
// Original: arm9/ov017 @ 0x021CBFF4; symbol: GameState_UpdateEnabledFlagForMatchingRecord; size: 0x5C.
// When the current embedded object is valid and its key matches the record, copies the record enabled flag to GameState+0x5728.
extern "C" void GameState_UpdateEnabledFlagForMatchingRecord(void *unused, void *record, unsigned ignored, void *state) {
    void *embedded = *(void **)((char *)state + 0x3718);
    if (!embedded || !*((unsigned char *)embedded + 3)) return;
    void *field = FieldBattle_GetEncounterRequest(embedded);
    if (!field || *(unsigned short *)((char *)field + 8) != *(unsigned short *)((char *)record + 4)) return;
    void *game = _ZN9GameState11GetInstanceEv();
    *(unsigned char *)((char *)game + 0x5728) = *((unsigned char *)record + 6) != 0;
}
