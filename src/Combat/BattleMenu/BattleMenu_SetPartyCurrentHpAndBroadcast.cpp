#include <globaldefs.h>
ARM
extern "C" void BattleMenu_BroadcastPartyDisplayStats(void *);
// Original: arm9/ov000 @ 0x02176134; symbol: SetRecordHalfwordAtOffsetCAndRefresh; size: 0x1C.
// Updates signed halfword +0xC only when changed, then calls the record refresh routine.
extern "C" void BattleMenu_SetPartyCurrentHpAndBroadcast(void *object, short value) {
    short *field = (short *)((unsigned char *)object + 0xc);
    if (value == *field) return;
    *field = value;
    BattleMenu_BroadcastPartyDisplayStats(object);
}
