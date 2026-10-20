#include <globaldefs.h>
extern "C" int CombatStatus_HasAilmentModeTwo(void*);
extern "C" void BattleAI_AppendGuaranteedSecondaryEffect(void*, unsigned);
// Original: arm9/ov024 @ 0x021FD3F0; symbol: func_ov024_021fd3f0; size: 0x38.
extern "C" ARM void Ov024_UpdateWhenModeTwoAndInactive(void* object) {
    void* nested = *(void**)((char*)object + 0x668);
    if (!CombatStatus_HasAilmentModeTwo(*(void**)((char*)nested + 0x138))) return;
    if (*((unsigned char*)object + 0x661)) return;
    BattleAI_AppendGuaranteedSecondaryEffect(object, 2);
}
