#include <globaldefs.h>
ARM
struct LinkedDescriptorView;
extern "C" int CombatStatus_CanReceiveEvaluatedDescriptorEffect(LinkedDescriptorView* p);
extern "C" int CombatStatus_CanApplySleep(char* p);
extern "C" bool CombatStatus_HasSleep(unsigned int* p);
extern "C" void BattleAI_CacheActionPolicyEntry(void*,int);
extern "C" void SubmitPercentScaledDisplayRecord(void*,float,int);
struct PercentageRecord { char pad[20]; unsigned low : 7; unsigned percentage : 7; unsigned high : 18; };
// Original: arm9/ov024 @ 0x021FD45C; symbol: func_ov024_021fd45c; size: 0xA8.
extern "C" void BattleAI_AppendDamageRecoverableAilmentChance(char *self) {
    char *object = *(char **)(self + 0x668);
    if (!CombatStatus_CanReceiveEvaluatedDescriptorEffect((LinkedDescriptorView *)object)) return;
    if (!CombatStatus_CanApplySleep(*(char **)(object + 0x138))) return;
    if (CombatStatus_HasSleep(*(unsigned **)(object + 0x138))) return;
    PercentageRecord *record = *(PercentageRecord **)(self + 0x64c);
    float percentage = (float)record->percentage;
    float scale = (float)*(unsigned char *)(*(char **)(object + 0x138) + 0x47) / 100.0f;
    float value = percentage * scale;
    if (value > 100.0f) value = 100.0f;
    BattleAI_CacheActionPolicyEntry(self,1);
    SubmitPercentScaledDisplayRecord(self,value,4);
}
