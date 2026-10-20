#include <globaldefs.h>

ARM
struct ModeDescriptor {
    unsigned char pad0[0x20];
    unsigned int firstPacked;
    unsigned int secondPacked;
    unsigned char pad28[8];
    short mode;
};
extern "C" char *_Z16GetCombatantByIDii(int, int);
extern "C" bool CombatStatus_CanApplyAttributeWard(unsigned int *);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int, int, int);
extern "C" void CombatStatus_ApplyAttributeWardModeOne(char *);
extern "C" void CombatStatus_ApplyAttributeWardModeTwo(unsigned char *);
extern "C" void CombatStatus_ApplyAttributeWardModeThree(unsigned char *);
extern "C" void CombatStatus_ApplyAttributeWardModeFour(char *);
extern "C" void CombatStatus_ApplyAttributeWardModeFive(unsigned char *);
extern "C" void *Combat_ClearCurrentResultNodeSlot(unsigned char *);
extern "C" void Combat_AppendResultMessage(void *, void *, unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void *, void *, void *, int, int, int, int);
// Original: arm9/ov024 @ 0x021DFF3C; symbol: func_ov024_021dff3c; size: 0x184.
// Selects a descriptor halfword and applies the requested combatant mode.
void *Combat_SelectDescriptorHalfwordAndApplyMode(char *self, int unused,
                                                   int index, ModeDescriptor *descriptor,
                                                   int unused4, int unused5,
                                                   unsigned char allowMode)
{
    char *combatant = _Z16GetCombatantByIDii(*(int *)(self + 0x10), index);
    if (!combatant)
        return 0;

    unsigned short selected;
    if (descriptor->mode > 0) {
        if (CombatStatus_CanApplyAttributeWard((unsigned int *)*(char **)(combatant + 0x138)) &&
            allowMode) {
            struct HighField { unsigned pad:20; unsigned value:10; unsigned rest:2; };
            struct LowField { unsigned value:10; unsigned pad:22; };
            unsigned int first = ((HighField *)&descriptor->firstPacked)->value;
            unsigned int second = ((LowField *)&descriptor->secondPacked)->value;
            selected = Combat_SelectMessageForPartyOrMonster(index, first, second);
            switch (descriptor->mode) {
            case 1:
                CombatStatus_ApplyAttributeWardModeOne(*(char **)(combatant + 0x138));
                break;
            case 2:
                CombatStatus_ApplyAttributeWardModeTwo((unsigned char *)*(char **)(combatant + 0x138));
                break;
            case 3:
                CombatStatus_ApplyAttributeWardModeThree((unsigned char *)*(char **)(combatant + 0x138));
                break;
            case 4:
                CombatStatus_ApplyAttributeWardModeFour(*(char **)(combatant + 0x138));
                break;
            case 5:
                CombatStatus_ApplyAttributeWardModeFive((unsigned char *)*(char **)(combatant + 0x138));
                break;
            }
        } else {
            struct FallbackFields { unsigned low:10; unsigned first:10; unsigned second:10; unsigned high:2; };
            FallbackFields *fields = (FallbackFields *)&descriptor->secondPacked;
            selected = Combat_SelectMessageForPartyOrMonster(index, fields->first, fields->second);
        }
    } else {
        struct FallbackFields { unsigned low:10; unsigned first:10; unsigned second:10; unsigned high:2; };
        FallbackFields *fields = (FallbackFields *)&descriptor->secondPacked;
        selected = Combat_SelectMessageForPartyOrMonster(index, fields->first, fields->second);
    }

    void *current = Combat_ClearCurrentResultNodeSlot((unsigned char *)*(void **)(self + 0x10));
    if (!current)
        return 0;
    Combat_AppendResultMessage(*(void **)(self + 0x10), current, selected);
    unsigned char *state = *(unsigned char **)(self + 0xc);
    int enabled = (((unsigned)state[0x1c] << 24) >> 31) != 0;
    Combat_PopulateResultWithCurrentHealthAndMagic(*(void **)(self + 0x10), current, combatant, 0, 0, 0, enabled);
    return current;
}
