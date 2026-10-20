#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetObjectWithFlag100(void *, int);
extern "C" char *BattleMenu_FindPartyCommandRecord(char *, int);
// Original: arm9/ov000 @ 0x02175754; symbol: func_ov000_02175754; size: 0x58.
// Visits four slot records and copies each resolved object component value at 0x138->0x14 into slot offset 0x28.
extern "C" void GameState_RefreshFourSlotLinkedObjectValues(char *obj) {
    void *state = _ZN9GameState11GetInstanceEv();
    for (int i = 0; i < 4; ++i) {
        char *record = BattleMenu_FindPartyCommandRecord(obj, i);
        if (record != 0) {
            void *object = GameState_GetObjectWithFlag100(state, *(int *)(record + 0x4c));
            if (object != 0) *(unsigned int *)(record + 0x28) = *(unsigned int *)(*(unsigned int *)((char *)object + 0x138) + 0x14);
        }
    }
}
