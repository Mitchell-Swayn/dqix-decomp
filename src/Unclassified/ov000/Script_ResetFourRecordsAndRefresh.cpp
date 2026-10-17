#include <globaldefs.h>
ARM
extern "C" void *FindFourSlotRecordByIndex(void *, unsigned int);
extern "C" void func_ov000_02174b14(void *);
// Original: arm9/ov000 @ 0x021813D4; symbol: func_ov000_021813d4; size: 0x58.
extern "C" void Script_ResetFourRecordsAndRefresh(void *owner) {
    for (int i = 0; i < 4; i++) {
        void *record = FindFourSlotRecordByIndex(owner, i);
        if (record != 0) {
            signed char offset = *(signed char *)((char *)record + 0x18);
            *((unsigned char *)record + offset + 0x10) = 0x64;
            *((unsigned char *)record + 0x24) &= ~4;
            func_ov000_02174b14(owner);
        }
    }
}
