#include <globaldefs.h>
ARM
extern "C" int ZoneState2754_FindPrimaryRecordByKey(void *, int);
// Original: arm9/ov000 @ 0x021815E4; symbol: func_ov000_021815e4; size: 0x24.
extern "C" int BattleMenu_FindSelectedEquipmentRecord(unsigned char *p) {
    int index = *(signed char *)(p + 0x1d6f);
    int key = *(signed short *)(p + index * 2 + 0x26);
    return ZoneState2754_FindPrimaryRecordByKey(p + 0x100, key);
}
