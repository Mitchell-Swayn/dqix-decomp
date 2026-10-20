#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
bool GameObject_IsDead(void*);
void GameObject_SetCombatRecoveryMarker(char* p,int v);
int _Z13NextRandomMaxP6Randomi(void*,int);
void CombatStatus_ClearAttackStage(char *p);
void CombatStatus_ClearDefenseStage(char* p);
void CombatStatus_ClearAgilityStage(unsigned char* p);
void CombatStatus_ClearCharmStage(char *p);
void CombatStatus_ClearMagicalMightStage(char* p);
void CombatStatus_ClearMagicalMendingModifier(unsigned char* p);
void CombatStatus_ClearSpellResistanceStage(char *p);
void CombatStatus_ClearBreathResistanceStage(char* p);
void CombatStatus_ClearEvasionStage(unsigned char* p);
void CombatStatus_ClearShieldBlockStage(char *p);
void CombatStatus_ClearActionRestriction(unsigned char* p);
bool CombatStatus_HasAttributeWard(unsigned int* p);
void CombatStatus_ClearAttributeWard(char *p);
void CombatStatus_ClearDazzle(char *p);
void CombatStatus_ClearFizzle(char *p);
void CombatStatus_ClearBounce(char* p);
void CombatStatus_ClearReverseCycle(unsigned char* p);
void CombatantState_ClearVanish(char *p);
void CombatantState_ClearFeelTheBurn(char* p);
void CombatantState_ClearRotstopper(unsigned char* p);
void CombatantState_ClearFatalDamageProtection(unsigned char* p);
void CombatantState_ClearFireBarrier(char* p);
void CombatantState_ClearIceBarrier(unsigned char* p);
void CombatantState_ClearHolyImpregnable(unsigned char* p);
void CombatantState_ClearEerieLight(char* p);
void CombatantState_ClearTwocusPocus(char *p);
void CombatantState_ClearLinkedCombatEffect(unsigned char* p);
void CombatantState_ClearZeroZone(unsigned char* p);
void CombatantState_ClearRoughAndTumble(char *p);
int Combat_IsMpCostWaived(char* p);
int Combat_IsCombatantExcludedFromSelection(char* p);
int Combat_HasForcedTarget(void* object);
int Combat_HasReducedTargetWeightStatus(void* object);
int Combat_HasShieldBlockModifier(void* object);
int Combat_HasEvasionModifier(const void* object);
int Combat_HasFixedReactionChanceStatus(void *object);
int Combat_HasAccuracyImpairmentStatus(void* object);
int Ov000_TestNestedFlagBit3(void *object);
int Combat_HasIncreasedStatusSusceptibility(void* object);
int Combat_HasFizzle(const void* object);
unsigned int Combat_HasBounce(void* p);
int Combat_HasFeelTheBurn(void* object);
int Combat_HasRotstopper(void *p);
int Combat_HasReverseCycle(void* object);
int Combat_HasAlmaMater(void* object);
int Ov000_TestNestedFlagBit1(void *object);
int Combat_HasIceBarrier(const void* object);
unsigned Combat_HasTimedAttackModifier(void *object);
int Combat_HasDefenseStageModifier(void *p);
int Combat_HasTimedAgilityModifier(void *object);
int Combat_HasTimedCharmModifier(void *object);
int Combat_HasTimedMagicalMightModifier(void *p);
int Ov000_TestNestedFlagBit8(void *object);
void* Combat_ClearCurrentResultNodeSlot(unsigned char* p);
char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
void Combat_AppendStatusRecoveryResult(unsigned char*,void*,char*,int,int,int);
void _Z21UpdateCombatantAttackii(int,int);
void _Z22UpdateCombatantDefenseii(int,int);
void _Z22UpdateCombatantAgilityii(int,int);
void _Z20UpdateCombatantCharmii(int,int);
void _Z27UpdateCombatantMagicalMightii(int,int);
int Combat_HasTimedMagicalMendingModifier(void*);
void _Z29UpdateCombatantMagicalMendingii(int,int);
int Combat_HasSpellResistanceModifier(void*);
int Combat_HasBreathResistanceModifier(void*);
extern const float Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[],Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants_Copy2[];
}
struct StatusModeFlags {unsigned short low:9;unsigned short mode:3;unsigned short high:4;};
struct StatusByteFlags {unsigned char bit0:1;unsigned char bit1:1;unsigned char rest:6;};
inline int IsPartyIndex(int id) {return id>=0 && id<=3;}
// Original: arm9/ov000 @ 0x0215858C; symbol: func_ov000_0215858c; size: 0x12D0.
// Decrements status timers, tests probability tables, clears expired flags, and emits status messages.
extern "C" void Combat_UpdateTimedStatusRecovery(unsigned char* contextArg,int idArg,int messageArg) {
 int messageContext=messageArg;
 int id=idArg;
 unsigned char* context=contextArg;
 unsigned char* status;
 char* object=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),id);
 if(!object)return;
 float initialChance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 status=*(unsigned char**)(object+0x138);
 if(((StatusByteFlags*)(status+0x3b))->bit1) {
 CombatStatus_ClearActionRestriction(status);
 (*(unsigned char**)(object+0x138))[0x3c]|=0x40;
 }
 if(Combat_HasForcedTarget(object)) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 if(status[0x7e]) {if(!--status[0x7e]) {status[0x7e]=0;status[0xa1]=1;}}
 int linkedId=*(short*)(*(char**)(object+0x138)+0x2e);
 int invalid=0;
 char* linked;
 void* game=_ZN9GameState11GetInstanceEv();
 linked=_ZN9GameState19GetCombatantByIndexEi(game,linkedId);
 if(!linked)invalid=1;
 if(linked && GameObject_IsDead(linked))invalid=1;
 if(linked && Combat_IsCombatantExcludedFromSelection(linked))invalid=1;
 if(invalid) {
 status[0xa1]=0;
 CombatantState_ClearLinkedCombatEffect(*(unsigned char**)(object+0x138));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x164,0);
 }else if(status[0xa1]) {
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[--status[0xa1]]>initialChance) {
 status[0xa1]=0;
 CombatantState_ClearLinkedCombatEffect(*(unsigned char**)(object+0x138));
 int party=IsPartyIndex(id);
 if(!party)GameObject_SetCombatRecoveryMarker(object,1);
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x164,0);
 }
 }
 }
 // Status timer at 0x82; target block 0x2158760.
 if(Combat_HasAccuracyImpairmentStatus(object) && status[0x82]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x82];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants_Copy2[status[0x82]]>chance) {
 status[0x82]=0;
 CombatStatus_ClearDazzle((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1c7,0);
 }
 }
 // Status timer at 0x83; target block 0x21587f8.
 if(Combat_HasFizzle(object) && status[0x83]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x83];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x83]]>chance) {
 status[0x83]=0;
 CombatStatus_ClearFizzle((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1d6,45);
 }
 }
 // Status timer at 0x84; target block 0x2158890.
 if(Combat_HasBounce(object) && status[0x84]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x84];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x84]]>chance) {
 status[0x84]=0;
 CombatStatus_ClearBounce((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1c3,0);
 }
 }
 // Status timer at 0x85; target block 0x2158928.
 if(Combat_HasReducedTargetWeightStatus(object) && status[0x85]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x85];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants_Copy2[status[0x85]]>chance) {
 status[0x85]=0;
 CombatantState_ClearVanish((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1c9,40);
 }
 }
 // Status timer at 0x86; target block 0x21589c0.
 if(Combat_HasFeelTheBurn(object) && status[0x86]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x86];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants_Copy2[status[0x86]]>chance) {
 status[0x86]=0;
 CombatantState_ClearFeelTheBurn((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1d7,0);
 }
 }
 // Status timer at 0x87; target block 0x2158a58.
 if(Combat_HasRotstopper(object) && status[0x87]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x87];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants_Copy2[status[0x87]]>chance) {
 status[0x87]=0;
 CombatantState_ClearRotstopper((unsigned char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1d8,0);
 }
 }
 // Status timer at 0x89; target block 0x2158af0.
 if(Combat_HasReverseCycle(object) && status[0x89]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x89];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x89]]>chance) {
 status[0x89]=0;
 CombatStatus_ClearReverseCycle((unsigned char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1c4,0);
 }
 }
 // Status timer at 0x8a; target block 0x2158b88.
 if(Combat_HasAlmaMater(object) && status[0x8a]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x8a];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x8a]]>chance) {
 status[0x8a]=0;
 CombatantState_ClearFatalDamageProtection((unsigned char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1cb,0);
 }
 }
 if(CombatStatus_HasAttributeWard((unsigned int*)*(char**)(object+0x138)) && status[0x8d]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x8d];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants_Copy2[status[0x8d]]>chance) {
 status[0x8d]=0;
 unsigned mode=((StatusModeFlags*)(*(char**)(object+0x138)+0x22))->mode;
 CombatStatus_ClearAttributeWard(*(char**)(object+0x138));
 switch(mode) {
 case 1:Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x219,0);break;
 case 2:Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x21a,0);break;
 case 3:Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x21b,0);break;
 case 4:Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x21c,0);break;
 case 5:Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x21d,0);break;
 }
 }
 }
 // Status timer at 0x8e; target block 0x2158de4.
 if(Ov000_TestNestedFlagBit3(object) && status[0x8e]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x8e];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x8e]]>chance) {
 status[0x8e]=0;
 CombatantState_ClearHolyImpregnable((unsigned char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x25d,0);
 }
 }
 // Status timer at 0x9e; target block 0x2158e7c.
 if(Combat_HasIncreasedStatusSusceptibility(object) && status[0x9e]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x9e];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x9e]]>chance) {
 status[0x9e]=0;
 CombatantState_ClearEerieLight((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x25e,0);
 }
 }
 // Status timer at 0x8f; target block 0x2158f14.
 if(Ov000_TestNestedFlagBit1(object) && status[0x8f]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x8f];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x8f]]>chance) {
 status[0x8f]=0;
 CombatantState_ClearFireBarrier((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1cc,0);
 }
 }
 // Status timer at 0x90; target block 0x2158fac.
 if(Combat_HasIceBarrier(object) && status[0x90]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x90];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x90]]>chance) {
 status[0x90]=0;
 CombatantState_ClearIceBarrier((unsigned char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1cd,0);
 }
 }
 // Status timer at 0x91; target block 0x2159044.
 if(Combat_HasTimedAttackModifier(object) && status[0x91]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x91];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x91]]>chance) {
 status[0x91]=0;
 CombatStatus_ClearAttackStage((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1ce,0);
 _Z21UpdateCombatantAttackii((int)context,id);
 }
 }
 // Status timer at 0x92; target block 0x21590e8.
 if(Combat_HasDefenseStageModifier(object) && status[0x92]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x92];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x92]]>chance) {
 status[0x92]=0;
 CombatStatus_ClearDefenseStage((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1cf,0);
 _Z22UpdateCombatantDefenseii((int)context,id);
 }
 }
 // Status timer at 0x93; target block 0x215918c.
 if(Combat_HasTimedAgilityModifier(object) && status[0x93]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x93];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x93]]>chance) {
 status[0x93]=0;
 CombatStatus_ClearAgilityStage((unsigned char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1db,0);
 _Z22UpdateCombatantAgilityii((int)context,id);
 }
 }
 // Status timer at 0x94; target block 0x2159230.
 if(Combat_HasTimedCharmModifier(object) && status[0x94]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x94];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x94]]>chance) {
 status[0x94]=0;
 CombatStatus_ClearCharmStage((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1d0,0);
 _Z20UpdateCombatantCharmii((int)context,id);
 }
 }
 // Status timer at 0x95; target block 0x21592d4.
 if(Combat_HasTimedMagicalMightModifier(object) && status[0x95]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x95];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x95]]>chance) {
 status[0x95]=0;
 CombatStatus_ClearMagicalMightStage((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1d1,0);
 _Z27UpdateCombatantMagicalMightii((int)context,id);
 }
 }
 // Status timer at 0x96; target block 0x2159378.
 if(Combat_HasTimedMagicalMendingModifier(object) && status[0x96]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x96];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x96]]>chance) {
 status[0x96]=0;
 CombatStatus_ClearMagicalMendingModifier((unsigned char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1d2,0);
 _Z29UpdateCombatantMagicalMendingii((int)context,id);
 }
 }
 // Status timer at 0x97; target block 0x215941c.
 if(Combat_HasSpellResistanceModifier(object) && status[0x97]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x97];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants_Copy2[status[0x97]]>chance) {
 status[0x97]=0;
 CombatStatus_ClearSpellResistanceStage((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1d3,0);
 }
 }
 // Status timer at 0x98; target block 0x21594b4.
 if(Combat_HasBreathResistanceModifier(object) && status[0x98]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x98];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0x98]]>chance) {
 status[0x98]=0;
 CombatStatus_ClearBreathResistanceStage((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1d4,0);
 }
 }
 // Status timer at 0x99; target block 0x215954c.
 if(Combat_HasShieldBlockModifier(object) && status[0x99]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x99];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants_Copy2[status[0x99]]>chance) {
 status[0x99]=0;
 CombatStatus_ClearShieldBlockStage((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1d5,0);
 }
 }
 // Status timer at 0x9a; target block 0x21595e4.
 if(Combat_HasEvasionModifier(object) && status[0x9a]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x9a];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants_Copy2[status[0x9a]]>chance) {
 status[0x9a]=0;
 CombatStatus_ClearEvasionStage((unsigned char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1d9,0);
 }
 }
 // Status timer at 0x9b; target block 0x215967c.
 if(Combat_IsMpCostWaived((char*)object) && status[0x9b]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x9b];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants_Copy2[status[0x9b]]>chance) {
 status[0x9b]=0;
 CombatantState_ClearZeroZone((unsigned char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1c5,0);
 }
 }
 // Status timer at 0x9c; target block 0x2159714.
 if(Combat_HasFixedReactionChanceStatus(object) && status[0x9c]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0x9c];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants_Copy2[status[0x9c]]>chance) {
 status[0x9c]=0;
 CombatantState_ClearRoughAndTumble((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x1da,0);
 }
 }
 // Status timer at 0xa0; target block 0x21597ac.
 if(Ov000_TestNestedFlagBit8(object) && status[0xa0]) {
 void* entry=Combat_ClearCurrentResultNodeSlot(context);if(!entry)return;
 --status[0xa0];
 float chance=(float)_Z13NextRandomMaxP6Randomi(context,100)/100.0f;
 if(Combat_UpdateTimedStatusRecovery_StatusRecoveryRatioConstants[status[0xa0]]>chance) {
 status[0xa0]=0;
 CombatantState_ClearTwocusPocus((char*)(*(unsigned char**)(object+0x138)));
 Combat_AppendStatusRecoveryResult(context,entry,object,messageContext,0x24b,0);
 }
 }
}
