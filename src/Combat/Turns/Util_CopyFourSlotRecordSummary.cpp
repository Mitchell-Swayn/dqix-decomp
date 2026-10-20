#include <globaldefs.h>
ARM
extern "C" char* BattleMenu_FindPartyCommandRecord(void*,int);
extern "C" unsigned BattleMenu_GetEnemyTargetGroupKey(void*,int);
extern "C" void* BattleMenu_GetEnemyTargetObjectId(void* object, int index);
// Original: arm9/ov000 @ 0x02162C14; symbol: func_ov000_02162c14; size: 0x7C.
extern "C" void Util_CopyFourSlotRecordSummary(char *self, int index, signed char *out) {
    char *record = BattleMenu_FindPartyCommandRecord(self + 0x3760, index);
    if (!record) return;
    out[0] = *(signed char*)(record + 0x10 + *(signed char*)(record + 0x18));
    out[1] = *(signed char*)(record + 0x1c);
    out[2] = BattleMenu_GetEnemyTargetGroupKey(self + 0x3760, *(signed char*)(record + 0x1d));
    out[3] = (unsigned)BattleMenu_GetEnemyTargetObjectId(self + 0x3760, *(signed char*)(record + 0x1d));
    *(short*)(out + 6) = *(short*)(record + 0x2c);
    out[4] = *(signed char*)(record + 0x2e);
    *(unsigned short*)(out + 8) = *(unsigned short*)(record + 0x26);
}
