#include <globaldefs.h>

struct DescriptorFlagView { unsigned char pad[0x14]; unsigned flags; };
struct LinkedDescriptorView { unsigned char pad[0x138]; DescriptorFlagView *descriptor; };
struct Flags { unsigned char p[0x1c]; unsigned char b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1; };

ARM
extern "C" char *_Z16GetCombatantByIDii(int, int);
extern "C" bool CombatStatus_CanApplyParalysis(unsigned int *);
extern "C" int Combatant_GetPartyStateValue(void *, int, int);
extern "C" ARM int Combat_HasOrdinaryTension(LinkedDescriptorView *);
extern "C" ARM int Combat_CanReplaceAilmentFlags(void *, unsigned int, unsigned int);
extern "C" void Combat_SetResultMaskFlag(void *, unsigned long long *, unsigned int);
extern "C" void ClearTransitionFlagsAndSetStateThree(unsigned char *);
extern "C" void *Combat_QueueTensionLossNotification(char *, void *, unsigned int, int);
extern "C" ARM void *Combat_ClearCurrentResultNodeSlot(unsigned char *);
extern "C" void Combat_SuppressMessageForExceptionalOutcome(void *, Flags *, unsigned short *);
extern "C" void Combat_AppendResultMessage(void *, void *, unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void *, void *, void *, int, unsigned long long, int);
// Original: arm9/ov024 @ 0x021DDC80; symbol: func_ov024_021ddc80; size: 0x188.
// Applies conditional combat flags and builds the linked result record.
void *Combat_BuildRecordWithConditionalMaskUpdates(char *self, int unused,
                                                    int index, char *descriptor,
                                                    int unused5, int unused6,
                                                    unsigned char enabled)
{
    char *combatant = _Z16GetCombatantByIDii(*(int *)(self + 0x10), index);
    if (!combatant)
        return 0;

    int update = 0;
    int flagsClear = CombatStatus_CanApplyParalysis(
        (unsigned int *)*(char **)(combatant + 0x138));
    if (flagsClear && enabled)
        update = 1;

    unsigned short code = (unsigned short)Combatant_GetPartyStateValue(self, index, update);
    struct LowTwelveBits { unsigned low:12; unsigned high:20; };
    if (((LowTwelveBits *)(descriptor + 4))->low == 0x393)
        code = 0;

    int linked = Combat_HasOrdinaryTension((LinkedDescriptorView *)combatant);
    unsigned long long mask = 0;
    if (update) {
        if (Combat_CanReplaceAilmentFlags(self,
                                                   *(unsigned int *)(*(char **)(combatant + 0x138) + 0x14), 8))
            Combat_SetResultMaskFlag(*(void **)(self + 0x10), &mask, 0x2b);
        ClearTransitionFlagsAndSetStateThree(
            (unsigned char *)*(char **)(combatant + 0x138));
        Combat_SetResultMaskFlag(*(void **)(self + 0x10), &mask, 0x18);
        ++*(int *)(self + 0x14);
        if (linked)
            Combat_QueueTensionLossNotification(self, combatant, 0, 0);
    }

    void *current = Combat_ClearCurrentResultNodeSlot(*(unsigned char **)(self + 0x10));
    if (!current)
        return 0;
    Combat_SuppressMessageForExceptionalOutcome(self, (Flags *)*(void **)(self + 0xc), &code);
    if (code)
        Combat_AppendResultMessage(*(void **)(self + 0x10), current, code);

    unsigned char *state = *(unsigned char **)(self + 0xc);
    int stateFlag = (((unsigned)state[0x1c] << 24) >> 31) != 0;
    Combat_PopulateResultWithCurrentHealthAndMagic(*(void **)(self + 0x10), current, combatant,
                        0, mask, stateFlag);
    return current;
}
