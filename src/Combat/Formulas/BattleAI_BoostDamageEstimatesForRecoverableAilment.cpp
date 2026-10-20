#include <globaldefs.h>
ARM
extern "C" int CombatStatus_HasAilmentModeOne(void*);
extern "C" int CombatStatus_HasAilmentModeTwo(void*);
extern "C" int CombatEffect_TargetHasParalysis(void*);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6CC0; symbol: func_ov024_021f6cc0; size: 0x64.
extern "C" int BattleAI_BoostDamageEstimatesForRecoverableAilment(unsigned char* self) {
    unsigned char* object = *(unsigned char**)(self + 4);
    if (CombatStatus_HasAilmentModeOne(*(void**)(object + 0x138)) ||
        CombatStatus_HasAilmentModeTwo(*(void**)(object + 0x138)) ||
        CombatEffect_TargetHasParalysis(object)) {
        *(unsigned*)(self + 0x1c) = _fmul(0x3fc00000, *(unsigned*)(self + 0x14));
        *(unsigned*)(self + 0x20) = _fmul(0x3fc00000, *(unsigned*)(self + 0x18));
    }
    return 1;
}
