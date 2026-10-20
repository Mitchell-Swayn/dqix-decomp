#include <globaldefs.h>
ARM
struct DescriptorFlagView { unsigned char pad[0x14]; unsigned flags; };
struct LinkedDescriptorView { unsigned char pad[0x138]; DescriptorFlagView *descriptor; };
struct Record { unsigned char padding[0x22]; unsigned short mode:2; unsigned short rest:14; };
struct A { char pad[0x14]; unsigned int flags; char pad2[10]; unsigned short mode:2; };
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" bool CombatStatus_HasSleep(unsigned int* p);
extern "C" int CombatEffect_TargetHasConfusion(unsigned char*);
extern "C" ARM int CombatEffect_TargetHasParalysis(LinkedDescriptorView* self);
extern "C" ARM int Combat_HasActionRestriction(LinkedDescriptorView* self);
extern "C" int CombatStatus_HasAilmentModeOne(Record* p);
extern "C" int CombatStatus_HasAilmentModeTwo(A *p);
extern "C" ARM int CombatEffect_TargetHasDazzle(void*);
extern "C" int CombatEffect_TargetHasFizzle(unsigned char*);
struct StatusFields{signed a:3,b:3,c:3,d:3,e:3,f:3,g:3,h:3,i:3,j:3,rest:2;};
struct PackedCodes { unsigned low:10, middle:10, high:10, rest:2; };
struct FlagByte { unsigned char low:7, flag:1; };
extern "C" bool CombatEffect_TargetHasEerieLight(const void*);
extern "C" void _Z19ApplyCombatantBuffsii(int,int);
extern "C" void CombatStatus_ClearSleep(char *p);
extern "C" void CombatStatus_ClearConfusion(char* p);
extern "C" void CombatStatus_ClearParalysis(unsigned char* p);
extern "C" void CombatStatus_ClearActionRestriction(unsigned char* p);
extern "C" void CombatStatus_ClearAilmentModeOne(char* p);
extern "C" void CombatStatus_ClearAilmentModeTwo(char *p);
extern "C" void CombatStatus_ClearDazzle(char *p);
extern "C" void CombatStatus_ClearFizzle(char *p);
extern "C" void CombatantState_ClearEerieLight(char* p);
extern "C" void CombatStatus_ClearAttackStage(char *p);
extern "C" void CombatStatus_ClearDefenseStage(char* p);
extern "C" void CombatStatus_ClearAgilityStage(unsigned char* p);
extern "C" void CombatStatus_ClearCharmStage(char *p);
extern "C" void CombatStatus_ClearMagicalMightStage(char* p);
extern "C" void CombatStatus_ClearMagicalMendingModifier(unsigned char* p);
extern "C" void CombatStatus_ClearSpellResistanceStage(char *p);
extern "C" void CombatStatus_ClearBreathResistanceStage(char* p);
extern "C" void CombatStatus_ClearEvasionStage(unsigned char* p);
extern "C" void CombatStatus_ClearShieldBlockStage(char *p);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int, int, int);
extern "C" ARM void *Combat_ClearCurrentResultNodeSlot(unsigned char *);
extern "C" void Combat_AppendResultMessage(void *, void *, unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void *, void *, void *, int, int, int, int);
// Original: arm9/ov024 @ 0x021DF454; symbol: func_ov024_021df454; size: 0x298.
// Clears the observed status groups, selects a descriptor halfword, and builds the result record.
extern "C" void *Combat_ClearStatusGroupsAndBuildRecord(char *self, int unused, int index, char *descriptor)
{
    char *combatant = _Z16GetCombatantByIDii(*(int *)(self + 0x10), index);
    if (!combatant)
        return 0;
    int cleared = 0;

    if (CombatStatus_HasAilmentModeOne((Record *)*(char **)(combatant + 0x138))) {
        CombatStatus_ClearAilmentModeOne(*(char **)(combatant + 0x138));
        ++cleared;
    }
    if (CombatStatus_HasAilmentModeTwo((A *)*(char **)(combatant + 0x138))) {
        CombatStatus_ClearAilmentModeTwo(*(char **)(combatant + 0x138));
        ++cleared;
    }
    if (CombatEffect_TargetHasDazzle(combatant)) {
        CombatStatus_ClearDazzle(*(char **)(combatant + 0x138));
        ++cleared;
    }
    if (CombatEffect_TargetHasFizzle((unsigned char *)combatant)) {
        CombatStatus_ClearFizzle(*(char **)(combatant + 0x138));
        ++cleared;
    }
    if (CombatEffect_TargetHasEerieLight(combatant)) {
        CombatantState_ClearEerieLight(*(char **)(combatant + 0x138));
        ++cleared;
    }
    if (((StatusFields *)(*(char **)(combatant + 0x138) + 0x58))->a < 0) {
        CombatStatus_ClearAttackStage(*(char **)(combatant + 0x138));
        ++cleared;
    }
    if (((StatusFields *)(*(char **)(combatant + 0x138) + 0x58))->b < 0) {
        CombatStatus_ClearDefenseStage(*(char **)(combatant + 0x138));
        ++cleared;
    }
    if (((StatusFields *)(*(char **)(combatant + 0x138) + 0x58))->c < 0) {
        CombatStatus_ClearAgilityStage(*(unsigned char **)(combatant + 0x138));
        ++cleared;
    }
    if (((StatusFields *)(*(char **)(combatant + 0x138) + 0x58))->d < 0) {
        CombatStatus_ClearCharmStage(*(char **)(combatant + 0x138));
        ++cleared;
    }
    if (((StatusFields *)(*(char **)(combatant + 0x138) + 0x58))->e < 0) {
        CombatStatus_ClearMagicalMightStage(*(char **)(combatant + 0x138));
        ++cleared;
    }
    if (((StatusFields *)(*(char **)(combatant + 0x138) + 0x58))->f < 0) {
        CombatStatus_ClearMagicalMendingModifier(*(unsigned char **)(combatant + 0x138));
        ++cleared;
    }
    if (((StatusFields *)(*(char **)(combatant + 0x138) + 0x58))->g < 0) {
        CombatStatus_ClearSpellResistanceStage(*(char **)(combatant + 0x138));
        ++cleared;
    }
    if (((StatusFields *)(*(char **)(combatant + 0x138) + 0x58))->h < 0) {
        CombatStatus_ClearBreathResistanceStage(*(char **)(combatant + 0x138));
        ++cleared;
    }
    if (((StatusFields *)(*(char **)(combatant + 0x138) + 0x58))->j < 0) {
        CombatStatus_ClearEvasionStage(*(unsigned char **)(combatant + 0x138));
        ++cleared;
    }
    if (((StatusFields *)(*(char **)(combatant + 0x138) + 0x58))->i < 0) {
        CombatStatus_ClearShieldBlockStage(*(char **)(combatant + 0x138));
        ++cleared;
    }

    unsigned int selected;
    if (cleared > 0)
        selected = Combat_SelectMessageForPartyOrMonster(index, ((PackedCodes *)(descriptor + 0x20))->high, ((PackedCodes *)(descriptor + 0x24))->low);
    else
        selected = Combat_SelectMessageForPartyOrMonster(index, ((PackedCodes *)(descriptor + 0x24))->middle, ((PackedCodes *)(descriptor + 0x24))->high);

    _Z19ApplyCombatantBuffsii(*(int *)(self + 0x10), index);
    void *result = Combat_ClearCurrentResultNodeSlot(*(unsigned char **)(self + 0x10));
    if (!result)
        return 0;
    Combat_AppendResultMessage(*(void **)(self + 0x10), result, selected);
    int flag = ((FlagByte *)(*(char **)(self + 0x0c) + 0x1c))->flag != 0;
    Combat_PopulateResultWithCurrentHealthAndMagic(*(void **)(self + 0x10), result, combatant, 0, 0, 0, flag);
    return result;
}
