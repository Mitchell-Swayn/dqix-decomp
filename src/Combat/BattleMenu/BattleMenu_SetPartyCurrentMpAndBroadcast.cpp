#include <globaldefs.h>
ARM
extern "C" void BattleMenu_BroadcastPartyDisplayStats(void *object);
// Original: arm9/ov000 @ 0x02176150; symbol: func_ov000_02176150; size: 0x1C.
extern "C" void BattleMenu_SetPartyCurrentMpAndBroadcast(void *object, int value) {
    if (value == *(signed short *)((char *)object + 0xe))
        return;
    *(unsigned short *)((char *)object + 0xe) = value;
    BattleMenu_BroadcastPartyDisplayStats(object);
}
