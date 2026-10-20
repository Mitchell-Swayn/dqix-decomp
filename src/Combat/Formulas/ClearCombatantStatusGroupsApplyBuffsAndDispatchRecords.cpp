#include <globaldefs.h>

struct DescriptorFlagView { unsigned char pad[0x14]; unsigned flags; };
struct LinkedDescriptorView { unsigned char pad[0x138]; DescriptorFlagView *descriptor; };
extern "C" char *_Z16GetCombatantByIDii(int,int);
extern "C" ARM int Combat_HasOrdinaryTension(LinkedDescriptorView* self);
extern "C" ARM int Combat_HasSuperHighTension(void*);
extern "C" void CombatStatus_ClearOrdinaryTension(unsigned char* p);
extern "C" void CombatStatus_ClearSuperHighTension(char* p);
extern "C" void CombatStatus_ClearBounce(char* p);
extern "C" void CombatantState_ClearVanish(char *p);
extern "C" void CombatantState_ClearFeelTheBurn(char* p);
extern "C" void CombatantState_ClearRotstopper(unsigned char* p);
extern "C" void CombatantState_ClearSchizofanic(int self);
extern "C" void CombatantState_ClearFatalDamageProtection(unsigned char* p);
extern "C" void CombatStatus_ClearReverseCycle(unsigned char* p);
extern "C" void CombatantState_ClearFocusPocus(char *p);
extern "C" void CombatStatus_ClearFizzle(char *p);
extern "C" void CombatantState_ClearMistMe(int self);
extern "C" void CombatantState_ClearRightAsRain(char* p);
extern "C" void CombatStatus_ClearAttributeWard(char *p);
extern "C" void CombatantState_ClearHolyImpregnable(unsigned char* p);
extern "C" void CombatantState_ClearEerieLight(char* p);
extern "C" void CombatantState_ClearFireBarrier(char* p);
extern "C" void CombatantState_ClearIceBarrier(unsigned char* p);
extern "C" void CombatantState_ClearZeroZone(unsigned char* p);
extern "C" void CombatantState_ClearRoughAndTumble(char *p);
extern "C" void CombatantState_ClearKnightWatch(char* p);
extern "C" void CombatantState_ClearTwocusPocus(char *p);
extern "C" void CombatStatus_ClearAttackStage(char *p);
extern "C" void CombatStatus_ClearDefenseStage(char* p);
extern "C" void CombatStatus_ClearAgilityStage(unsigned char* p);
extern "C" void CombatStatus_ClearCharmStage(char *p);
extern "C" void CombatStatus_ClearMagicalMightStage(char* p);
extern "C" void CombatStatus_ClearMagicalMendingModifier(unsigned char* p);
extern "C" void CombatStatus_ClearSpellResistanceStage(char *p);
extern "C" void CombatStatus_ClearBreathResistanceStage(char* p);
extern "C" void CombatStatus_ClearShieldBlockStage(char *p);
extern "C" void CombatStatus_ClearEvasionStage(unsigned char* p);
extern "C" void _Z19ApplyCombatantBuffsii(int,int);
extern "C" void *Combat_QueueTensionLossNotification(char*,void*,unsigned,int);
extern "C" void *GameState_CreateAndAppendIndexedRecord(void*,unsigned int);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,int,int,int);
// Original: arm9/ov024 @ 0x021EA85C; symbol: func_ov024_021ea85c; size: 0x1F4.
// Clears the observed combatant status fields, applies buffs, and dispatches linked records.
extern "C" void *ClearCombatantStatusGroupsApplyBuffsAndDispatchRecords(char *self,int index,unsigned mode,int unused) {
    char *combatant=_Z16GetCombatantByIDii(*(int*)(self+0x10),index);
    if(!combatant)return 0;
    int linkedFlag=Combat_HasOrdinaryTension((LinkedDescriptorView *)combatant);
    int recordFlag=Combat_HasSuperHighTension(combatant);
    CombatStatus_ClearOrdinaryTension((unsigned char *)*(char**)(combatant+0x138));
    CombatStatus_ClearSuperHighTension(*(char**)(combatant+0x138));
    CombatStatus_ClearBounce(*(char**)(combatant+0x138));
    CombatantState_ClearVanish(*(char**)(combatant+0x138));
    CombatantState_ClearFeelTheBurn(*(char**)(combatant+0x138));
    CombatantState_ClearRotstopper((unsigned char *)*(char**)(combatant+0x138));
    CombatantState_ClearSchizofanic((int)(unsigned)*(char**)(combatant+0x138));
    CombatantState_ClearFatalDamageProtection((unsigned char *)*(char**)(combatant+0x138));
    CombatStatus_ClearReverseCycle((unsigned char *)*(char**)(combatant+0x138));
    CombatantState_ClearFocusPocus(*(char**)(combatant+0x138));
    CombatStatus_ClearFizzle(*(char**)(combatant+0x138));
    CombatStatus_ClearReverseCycle((unsigned char *)*(char**)(combatant+0x138));
    CombatantState_ClearMistMe((int)(unsigned)*(char**)(combatant+0x138));
    CombatantState_ClearRightAsRain(*(char**)(combatant+0x138));
    CombatStatus_ClearAttributeWard(*(char**)(combatant+0x138));
    CombatantState_ClearHolyImpregnable((unsigned char *)*(char**)(combatant+0x138));
    CombatantState_ClearEerieLight(*(char**)(combatant+0x138));
    CombatantState_ClearFireBarrier(*(char**)(combatant+0x138));
    CombatantState_ClearIceBarrier((unsigned char *)*(char**)(combatant+0x138));
    CombatantState_ClearZeroZone((unsigned char *)*(char**)(combatant+0x138));
    CombatantState_ClearRoughAndTumble(*(char**)(combatant+0x138));
    CombatantState_ClearKnightWatch(*(char**)(combatant+0x138));
    CombatantState_ClearTwocusPocus(*(char**)(combatant+0x138));
    CombatStatus_ClearAttackStage(*(char**)(combatant+0x138));
    CombatStatus_ClearDefenseStage(*(char**)(combatant+0x138));
    CombatStatus_ClearAgilityStage((unsigned char *)*(char**)(combatant+0x138));
    CombatStatus_ClearCharmStage(*(char**)(combatant+0x138));
    CombatStatus_ClearMagicalMightStage(*(char**)(combatant+0x138));
    CombatStatus_ClearMagicalMendingModifier((unsigned char *)*(char**)(combatant+0x138));
    CombatStatus_ClearSpellResistanceStage(*(char**)(combatant+0x138));
    CombatStatus_ClearBreathResistanceStage(*(char**)(combatant+0x138));
    CombatStatus_ClearShieldBlockStage(*(char**)(combatant+0x138));
    CombatStatus_ClearEvasionStage((unsigned char *)*(char**)(combatant+0x138));
    _Z19ApplyCombatantBuffsii(*(int*)(self+0x10),index);
    void *result=0;
    if(linkedFlag) result=Combat_QueueTensionLossNotification(self,combatant,0,mode);
    else if(recordFlag && !Combat_HasSuperHighTension(combatant))
        result=Combat_QueueTensionLossNotification(self,combatant,8,mode);
    if(mode!=0 && result==0) {
        result=GameState_CreateAndAppendIndexedRecord(self,0xf1);
        Combat_PopulateResultWithCurrentHealthAndMagic(*(void**)(self+0x10),result,combatant,0,0,0,0);
    }
    return result;
}
