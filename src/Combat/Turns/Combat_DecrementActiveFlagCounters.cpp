#include <globaldefs.h>
ARM
struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" bool CombatStatus_HasSleep(unsigned*);
extern "C" bool CombatStatus_HasAttributeWard(unsigned*);
extern "C" bool Combat_HasPartyOnlyRetargetingStatus(Object*);
extern "C" int Combat_IsMpCostWaived(char*);
extern "C" int Combat_HasFizzle(const void*);
extern "C" int Combat_HasEvasionModifier(const void*);
extern "C" int Combat_HasIceBarrier(const void*);
extern "C" unsigned Combat_HasBounce(void*);
extern "C" unsigned Combat_HasTimedAttackModifier(void*);
extern "C" int Combat_HasParalysis(void*);
extern "C" int Combat_HasFixedReactionChanceStatus(void*);
extern "C" int Combat_HasAccuracyImpairmentStatus(void*);
extern "C" int Combat_HasReducedTargetWeightStatus(void*);
extern "C" int Combat_HasFeelTheBurn(void*);
extern "C" int Combat_HasRotstopper(void*);
extern "C" int Combat_HasReverseCycle(void*);
extern "C" int Combat_HasAlmaMater(void*);
extern "C" int Ov000_TestNestedFlagBit3(void*);
extern "C" int Combat_HasIncreasedStatusSusceptibility(void*);
extern "C" int Ov000_TestNestedFlagBit1(void*);
extern "C" int Combat_HasDefenseStageModifier(void*);
extern "C" int Combat_HasTimedAgilityModifier(void*);
extern "C" int Combat_HasTimedCharmModifier(void*);
extern "C" int Combat_HasTimedMagicalMightModifier(void*);
extern "C" int Combat_HasTimedMagicalMendingModifier(void*);
extern "C" int Combat_HasSpellResistanceModifier(void*);
extern "C" int Combat_HasBreathResistanceModifier(void*);
extern "C" int Combat_HasShieldBlockModifier(void*);
extern "C" int Ov000_TestNestedFlagBit8(void*);
// Original data: arm9/ov000 @ 0x2182a94; symbol: data_ov000_02182a94.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000100000002000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" int CombatDecrementActiveFlagCounters_UnknownRoleInitializedBytes[];
struct Mapping {int index,value;};
extern "C" Mapping Combat_DecrementActiveFlagCounters_StatusDecayReplacementPairs[];
// Original: arm9/ov000 @ 0x021599F4; symbol: func_ov000_021599f4; size: 0x264.
extern "C" void Combat_DecrementActiveFlagCounters(void*,int index) {
 unsigned char* object=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),index);
 if(!object) return;
 unsigned char* counters=*(unsigned char**)(object+0x138)+0x5c;
 unsigned char* states=*(unsigned char**)(object+0x138)+0x7f;
 unsigned char flags[29];
 flags[0]=Combat_HasParalysis(object);
 flags[1]=CombatStatus_HasSleep(*(unsigned**)(object+0x138));
 flags[2]=Combat_HasPartyOnlyRetargetingStatus((Object*)object);
 unsigned char active;
 unsigned char* test=flags;
 int* firstMap=CombatDecrementActiveFlagCounters_UnknownRoleInitializedBytes;
 for(int i=0;i<3;++i,++test,++firstMap) {
  active=*test;
  if(active) {
   if(counters[*firstMap]) {
    --counters[*firstMap];
    if(!counters[*firstMap]) {counters[*firstMap]=0;states[*firstMap]=4;}
   }
   break;
  }
 }
 flags[3]=Combat_HasFixedReactionChanceStatus(object);
 flags[4]=Combat_IsMpCostWaived((char*)object);
 flags[5]=Combat_HasAccuracyImpairmentStatus(object);
 flags[6]=Combat_HasFizzle(object);
 flags[7]=Combat_HasBounce(object);
 flags[8]=Combat_HasReducedTargetWeightStatus(object);
 flags[9]=Combat_HasFeelTheBurn(object);
 flags[10]=Combat_HasRotstopper(object);
 flags[11]=Combat_HasReverseCycle(object);
 flags[12]=Combat_HasAlmaMater(object);
 flags[13]=Ov000_TestNestedFlagBit3(object);
 flags[14]=CombatStatus_HasAttributeWard(*(unsigned**)(object+0x138));
 flags[15]=Combat_HasIncreasedStatusSusceptibility(object);
 flags[16]=Ov000_TestNestedFlagBit1(object);
 flags[17]=Combat_HasIceBarrier(object);
 flags[18]=Combat_HasTimedAttackModifier(object);
 flags[19]=Combat_HasDefenseStageModifier(object);
 flags[20]=Combat_HasTimedAgilityModifier(object);
 flags[21]=Combat_HasTimedCharmModifier(object);
 flags[22]=Combat_HasTimedMagicalMightModifier(object);
 flags[23]=Combat_HasTimedMagicalMendingModifier(object);
 flags[24]=Combat_HasSpellResistanceModifier(object);
 flags[25]=Combat_HasBreathResistanceModifier(object);
 flags[26]=Combat_HasShieldBlockModifier(object);
 flags[27]=Combat_HasEvasionModifier(object);
 flags[28]=Ov000_TestNestedFlagBit8(object);
 unsigned char value;
 int key;
 int zero=0;
 unsigned char* remaining=flags+3;
 Mapping* map=Combat_DecrementActiveFlagCounters_StatusDecayReplacementPairs;
 for(int i=0;i<26;++i,++remaining,++map) {
  value=*remaining;
  if(value) {
   key=map->index;
   value=counters[key];
   if(value) {
    counters[key]=value-1;
    key=map->index;
    value=counters[key];
    if(!value) {counters[key]=zero;states[map->index]=map->value;}
   }
  }
 }
}
