#include <globaldefs.h>

#include "Util/Random.h"

// Original: arm9/main @ 0x020744A8; symbol: _Z7RoundUpf; size: 0x18.
ARM int RoundUp(float attack) {
	return 0.5f + attack;
}

// Original: arm9/main @ 0x020744C0; symbol: _Z23CalculatePhysicalDamageiiP6Random; size: 0x12C.
ARM float CalculatePhysicalDamage(int attack, int defense, struct Random* random) {
    float atkAsFloat;
    float defAsFloat;
    if (random == NULL) {
        random = &data_02108ddc;
	}
    atkAsFloat = attack;
    defAsFloat = defense;
    defAsFloat /= 2.0f;
    atkAsFloat -= defAsFloat;
    atkAsFloat /= 2.0f;
    if (atkAsFloat <= 0) {
        atkAsFloat = 0;
    } else {
        float minimumDamage = attack;
        minimumDamage /= 16.0f;
        if (atkAsFloat <= minimumDamage) {
            atkAsFloat = attack;
            atkAsFloat /= 16.0f;
            atkAsFloat = NextRandomFloatBetween(random, 0.0f, atkAsFloat);
        } else {
            float flatVariance;
            float percentageVarianceMaximum;
            float percentageVariance;
            float percentageVarianceMinimum = atkAsFloat / 16.0f;
            percentageVarianceMinimum = 0.0f - percentageVarianceMinimum;
            percentageVarianceMaximum = atkAsFloat / 16.0f;
            percentageVariance = NextRandomFloatBetween(random, percentageVarianceMinimum, percentageVarianceMaximum);
            flatVariance = NextRandomFloatBetween(random, -1.0f, 1.0f);
            atkAsFloat += percentageVariance;
            atkAsFloat += flatVariance;
        }
    }
    if (atkAsFloat < 0) {
        atkAsFloat = 0;
    }
	return atkAsFloat;
}
// Original: arm9/main @ 0x020745EC; symbol: _Z29CalculateAttackBuffMultipliera; size: 0x24.
ARM float CalculateAttackBuffMultiplier(signed char buffLevel) {
    return 1.0f + 0.25f * buffLevel;
}

// Original: arm9/main @ 0x02074610; symbol: _Z30CalculateDefenseBuffMultipliera; size: 0x58.
ARM float CalculateDefenseBuffMultiplier(signed char buffLevel) {
    // increases defense by 50% for each positive level; for -1 do 50% defense reducation, for -2 do 75% defense reduction.
    float levelFloat;
    float multiplier;
    if (buffLevel >= 0) {
        levelFloat = buffLevel;
        multiplier = levelFloat * 0.5f;
        return 1.0f + multiplier;
    }
    levelFloat = buffLevel+1;
    multiplier = levelFloat * 0.25f;
    multiplier = multiplier - 0.5f;
    return 1.0f + multiplier;
}

// Original: arm9/main @ 0x02074668; symbol: _Z30CalculateAgilityBuffMultipliera; size: 0x58.
ARM float CalculateAgilityBuffMultiplier(signed char buffLevel) {
    // increases defense by 50% for each positive level; for -1 do 50% defense reducation, for -2 do 75% defense reduction. Identical to defense
    float levelFloat;
    float multiplier;
    if (buffLevel >= 0) {
        levelFloat = buffLevel;
        multiplier = levelFloat * 0.5f;
        return 1.0f + multiplier;
    }
    levelFloat = buffLevel+1;
    multiplier = levelFloat * 0.25f;
    multiplier = multiplier - 0.5f;
    return 1.0f + multiplier;
}

// Original: arm9/main @ 0x020746C0; symbol: _Z28CalculateCharmBuffMultipliera; size: 0x30.
ARM float CalculateCharmBuffMultiplier(signed char buffLevel) {
    return (buffLevel < 0) ? 1.0f : 1.0f + 0.5f * buffLevel;
}

// Original: arm9/main @ 0x020746F0; symbol: _Z35CalculateMagicalMightBuffMultipliera; size: 0x24.
ARM float CalculateMagicalMightBuffMultiplier(signed char buffLevel) {
    return 1.0f + 0.5f * buffLevel;
}

// Original: arm9/main @ 0x02074714; symbol: _Z37CalculateMagicalMendingBuffMultipliera; size: 0x24.
ARM float CalculateMagicalMendingBuffMultiplier(signed char buffLevel) {
    return 1.0f + 0.5f * buffLevel;
}