#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
extern "C" void *FindFourSlotRecordByIndex(void *, unsigned);
extern "C" unsigned func_ov000_0217f464(void *);
// Original: arm9/ov000 @ 0x0217FB98; symbol: func_ov000_0217fb98; size: 0x5C.
extern "C" unsigned AccumulateIndexedRecordFlags(void *owner) {
    unsigned result = 0;
    void *list = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    unsigned char count = *((unsigned char *)list + 0xf7c);
    for (unsigned char index = 0; index < count; ++index) {
        unsigned char recordIndex = *((unsigned char *)list + 0xf78 + index);
        void *record = FindFourSlotRecordByIndex(owner, recordIndex);
        if (record != 0) result |= func_ov000_0217f464(record);
    }
    return result;
}
