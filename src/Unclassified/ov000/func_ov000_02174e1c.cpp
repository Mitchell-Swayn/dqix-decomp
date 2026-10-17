#include <globaldefs.h>
ARM
extern "C" char *FindFourSlotRecordByIndex(char *p, int id);
// Original: arm9/ov000 @ 0x02174E1C; symbol: func_ov000_02174e1c; size: 0x18.
extern "C" char *func_ov000_02174e1c(char *p, int id) {
    char *record = FindFourSlotRecordByIndex(p, id);
    return record ? record + 0x68 : 0;
}
