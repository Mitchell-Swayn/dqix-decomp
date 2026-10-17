#include <globaldefs.h>
// Original: arm9/main @ 0x02074764; symbol: _Z21CalculateTensionBonusii; size: 0x40.
ARM float CalculateTensionBonus(int tension, int attackerLevel) {
    float levelMultiplier = attackerLevel / 10;
    levelMultiplier = 1.0f + levelMultiplier;
    return levelMultiplier * tension;
}