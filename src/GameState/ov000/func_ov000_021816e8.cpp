#include <globaldefs.h>
ARM
extern "C" char *FindFourSlotRecordByIndex(char *, int);
// Original: arm9/ov000 @ 0x021816E8; symbol: func_ov000_021816e8; size: 0x54.
extern "C" void func_ov000_021816e8(char *obj, int index) {
    if (index < 0) {
        for (int i = 0; i < 4; ++i) {
            char *record = FindFourSlotRecordByIndex(obj, i);
            if (record != 0) *(unsigned char *)(record + 0x445) = 0;
        }
    } else {
        char *record = FindFourSlotRecordByIndex(obj, index);
        if (record != 0) *(unsigned char *)(record + 0x445) = 0;
    }
}
