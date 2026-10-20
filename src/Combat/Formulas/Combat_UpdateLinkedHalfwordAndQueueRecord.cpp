#include <globaldefs.h>

ARM
extern "C" {
void *_Z16GetCombatantByIDii(int, int);
bool GameObject_IsDead(void *);
void CombatantState_ReviveWithHealth(unsigned char *, unsigned short);
void Combat_SetResultMaskFlag(void *, unsigned long long *, unsigned);
void *_ZN9GameState11GetInstanceEv(void);
void *GameState_GetObjectWithFlag100(void *, int);
float Combat_GetCurrentHealthFraction(unsigned char *);
short Combat_AddHealthUpToMaximum(void *, int, int, short *);
void *Combat_ClearCurrentResultNodeSlot(unsigned char *);
void Combat_AppendResultMessage(void *, void *, unsigned short);
void Combat_PopulateResultWithCurrentHealthAndMagic(int, void *, void *, int, unsigned long long, bool);
// Original: arm9/ov024 @ 0x021DE868; symbol: func_ov024_021de868; size: 0x174.
// Updates a combatant's linked halfword and queues the resulting record; exact gameplay role is unresolved.
void *Combat_UpdateLinkedHalfwordAndQueueRecord(char *self, int unused, int targetId)
{
    char *combatant = (char *)_Z16GetCombatantByIDii(*(int *)(self + 0x10), targetId);
    if (!combatant)
        return 0;

    short applied = 0;
    unsigned long long mask = 0;
    unsigned short code;
    if (GameObject_IsDead(combatant)) {
        CombatantState_ReviveWithHealth(
            *(unsigned char **)(combatant + 0x138),
            *(unsigned short *)(*(char **)(combatant + 0x138) + 4));
        Combat_SetResultMaskFlag(*(void **)(self + 0x10), &mask, 3);
        code = 0x20;
        unsigned char *nested = *(unsigned char **)(combatant + 0x138);
        nested[0x3b] = (nested[0x3b] & ~1) | 1;
        int inRange;
        if (targetId < 0) goto out_of_range;
        if (targetId <= 3) { inRange = 1; goto range_checked; }
    out_of_range:
        inRange = 0;
    range_checked:
        if (inRange != 0) {
            void *gameState = _ZN9GameState11GetInstanceEv();
            void *object = GameState_GetObjectWithFlag100(gameState, targetId);
            if (object)
                *(unsigned char *)(*(char **)((char *)object + 0x138) + 0x3a) = 1;
        }
    } else {
        float ratio = Combat_GetCurrentHealthFraction((unsigned char *)combatant);
        if (ratio < 1.0f) {
            unsigned char *nested = *(unsigned char **)(combatant + 0x138);
            Combat_AddHealthUpToMaximum(*(void **)(self + 0x10), targetId,
                                          *(unsigned short *)(nested + 4), &applied);
            Combat_SetResultMaskFlag(*(void **)(self + 0x10), &mask, 0x25);
            code = 0x16;
        } else {
            code = 0x1f;
        }
    }

    void *record = Combat_ClearCurrentResultNodeSlot(*(unsigned char **)(self + 0x10));
    if (!record)
        return 0;
    Combat_AppendResultMessage(*(void **)(self + 0x10), record, (unsigned short)code);
    unsigned char *state = *(unsigned char **)(self + 0xc);
    bool enabled = (((unsigned)state[0x1c] << 24) >> 31) != 0;
    Combat_PopulateResultWithCurrentHealthAndMagic(*(int *)(self + 0x10), record, combatant,
                         (short)-applied, mask, enabled);
    return record;
}
}
