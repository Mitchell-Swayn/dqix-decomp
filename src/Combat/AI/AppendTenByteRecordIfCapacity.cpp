#include <globaldefs.h>
ARM
extern "C" void BattleAI_CopyActionEffectRecord(unsigned char *, const unsigned char *);
// Original: arm9/ov024 @ 0x021F6A1C; symbol: func_ov024_021f6a1c; size: 0x30.
extern "C" void AppendTenByteRecordIfCapacity(unsigned char *object, const unsigned char *source) {
    int count = *(unsigned int *)(object + 0xc0);
    if (count >= 0x10) return;
    BattleAI_CopyActionEffectRecord(object + count * 0xc, source);
    *(unsigned int *)(object + 0xc0) = *(unsigned int *)(object + 0xc0) + 1;
}
