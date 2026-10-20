#include <globaldefs.h>
ARM
extern "C" void BattleScene_DrawWorldCombatantsAndSelectionEffects(void *);
// Original: arm9/ov017 @ 0x021B8408; symbol: func_ov017_021b8408; size: 0x18.
extern "C" void FieldBattle_DrawCombatantsAndSelectionEffects(void *object) {
    void *value = *(void **)((unsigned char *)object + 0x6ac);
    if (value != 0)
        BattleScene_DrawWorldCombatantsAndSelectionEffects(value);
}
