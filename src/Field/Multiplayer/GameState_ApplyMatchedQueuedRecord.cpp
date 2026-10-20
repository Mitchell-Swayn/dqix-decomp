#include <globaldefs.h>
ARM
extern "C" void BattleScene_EnableFlags(unsigned char* p,unsigned int bits);
struct Record { unsigned short id; unsigned short value : 15; unsigned short reserved : 1; unsigned char mode; signed char field; };
extern "C" void GameState_AppendSixByteRecord(void *, const Record *);
extern "C" void CombatScene_SetPendingRequestSelector(void *, int);
extern "C" void* FieldBattle_GetScene(void*);
extern "C" void* FieldBattle_GetEncounterRequest(void*);
// Original: arm9/ov017 @ 0x021CD424; symbol: func_ov017_021cd424; size: 0xA4.
extern "C" void GameState_ApplyMatchedQueuedRecord(void *unused0, unsigned char *input, int unused2, char *context) {
    void *object = *(void **)(context + 0x3718);
    char *header = (char *)FieldBattle_GetEncounterRequest(object);
    if (*(unsigned short *)(header + 8) == *(unsigned short *)(input + 4)) {
        unsigned char *state = (unsigned char *)FieldBattle_GetScene(object);
        if (state) {
            Record record;
            record.id = *(unsigned short *)(input + 6);
            record.value = *(unsigned short *)(input + 8);
            record.mode = input[11];
            record.field = *(signed char *)(input + 12);
            GameState_AppendSixByteRecord(state, &record);
            int value = *(signed char *)(input + 10);
            if (value >= 0) CombatScene_SetPendingRequestSelector(state, value);
            BattleScene_EnableFlags(state, 0x8000);
        }
    }
}
