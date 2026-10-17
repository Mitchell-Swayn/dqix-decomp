#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetObjectWithFlag100(void *, int);
extern "C" void *FindFourSlotRecordByIndex(void *, unsigned int);
extern "C" void func_ov000_02170db0(void *, unsigned int, unsigned int);
// Original: arm9/ov000 @ 0x02174514; symbol: func_ov000_02174514; size: 0x68.
extern "C" void GameState_RefreshFourIndexedRecordValues(void *owner) {
    void *game = _ZN9GameState11GetInstanceEv();
    for (int index = 0; index < 4; index++) {
        void *object = GameState_GetObjectWithFlag100(game, index);
        if (object != 0) {
            void *record = FindFourSlotRecordByIndex(owner, index);
            if (record != 0) {
                unsigned int oldValue = *(unsigned int *)((char *)record + 0x28);
                unsigned int newValue = *(unsigned int *)(*(char **)((char *)object + 0x138) + 0x14);
                if (oldValue != newValue) {
                    *(unsigned int *)((char *)record + 0x28) = newValue;
                    func_ov000_02170db0(record, oldValue, newValue);
                }
            }
        }
    }
}
