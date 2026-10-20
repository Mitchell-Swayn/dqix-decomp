#include <globaldefs.h>
ARM
extern "C" int CombatEffect_TargetHasConfusion(void*);
extern "C" void BattleAI_AppendGuaranteedSecondaryEffect(void*, int);
// Original: arm9/ov024 @ 0x021FD784; symbol: Object_ApplyMode7WhenDescriptorFlag20AndByte661Clear; size: 0x34.
// Applies mode 7 only when the descriptor at +0x668 has flag 0x20 and byte +0x661 is clear.
extern "C" void BattleAI_AppendFlag20RemovalWhenNotAlreadyQueued(unsigned char* self) {
    if (!CombatEffect_TargetHasConfusion(*(void**)(self + 0x668))) return;
    if (self[0x661]) return;
    BattleAI_AppendGuaranteedSecondaryEffect(self, 7);
}
