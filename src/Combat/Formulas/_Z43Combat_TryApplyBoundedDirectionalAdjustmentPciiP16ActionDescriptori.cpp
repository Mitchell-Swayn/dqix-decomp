#include <globaldefs.h>
#include <Util/Random.h>

ARM
struct ActionDescriptor { unsigned char pad[0x32]; short delta; };
extern "C" char *_Z16GetCombatantByIDii(int, int);
extern "C" int TestDirectionalSignedModeLimitUnlessDisabled(char *, int);
extern "C" int CombatStatus_AdjustAttackStageAndRefreshTimer(char *, int);
extern "C" void _Z21UpdateCombatantAttackii(int, int);
extern "C" unsigned int _ffltu(unsigned int);
extern "C" int _fflt(int);
extern "C" int _fgeq(int, int);
extern "C" int Combat_SelectAttackStageChangeMessage(char *, int, char *, int, signed char, unsigned char, unsigned char);
extern "C" void *GameState_CreateAndAppendIndexedRecord(void *, unsigned int);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void *, void *, void *, int, int, int, int);
// Original: arm9/ov024 @ 0x021E2EBC; symbol: func_ov024_021e2ebc; size: 0x180.
// Applies a bounded signed combatant adjustment after random and directional-mode checks.
unsigned long long Combat_TryApplyBoundedDirectionalAdjustment(char *self, int unused,
                                                                int combatantId,
                                                                ActionDescriptor *descriptor,
                                                                int enabled)
{
    if (enabled <= 0)
        return 0;

    char *combatant = _Z16GetCombatantByIDii(*(int *)(self + 0x10), combatantId);
    if (!combatant)
        return 0;

    int random = NextRandomMax((Random *)*(void **)(self + 0x10), 100);
    int delta = descriptor->delta;
    if (delta < -2)
        delta = -2;
    if (delta > 2)
        delta = 2;

    int direction = 0;
    if (delta < 0) {
        char *object = *(char **)(combatant + 0x138);
        unsigned char chance = *(unsigned char *)(object + 0x4f);
        if (!chance)
            return 0;
        unsigned char *state = *(unsigned char **)(self + 0xc);
        if (((((unsigned)state[0x1c] << 24) >> 31) == 0)) {
            unsigned int chanceFloat = _ffltu(chance);
            int randomFloat = _fflt(random);
            if (_fgeq(randomFloat, (int)chanceFloat))
                return 0;
        }
        direction = 1;
    }

    int accepted = 0;
    int result = 0;
    if (TestDirectionalSignedModeLimitUnlessDisabled(*(char **)(combatant + 0x138), direction & 0xff)) {
        result = CombatStatus_AdjustAttackStageAndRefreshTimer(*(char **)(combatant + 0x138), (signed char)delta);
        _Z21UpdateCombatantAttackii(*(int *)(self + 0x10), combatantId);
        accepted = 1;
    }
    if (accepted) {
        int action = Combat_SelectAttackStageChangeMessage(self, combatantId, (char *)descriptor,
                                                (unsigned char)direction, (signed char)result, 1, 1);
        void *record = GameState_CreateAndAppendIndexedRecord(self, (unsigned int)action);
        if (record)
            Combat_PopulateResultWithCurrentHealthAndMagic(*(void **)(self + 0x10), record, combatant, 0, 0, 0, 0);
    }
    return 0;
}
