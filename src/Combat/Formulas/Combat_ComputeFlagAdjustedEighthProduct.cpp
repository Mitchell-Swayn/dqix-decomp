#include <globaldefs.h>
ARM
struct GameState;struct RecordForFlag18;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
extern "C" float Combat_GetDamageStatusMultiplier(unsigned);
extern "C" int PartyRoster_ContainsActiveObjectIndex(unsigned char*,unsigned);
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_TestMonsterDescriptorMode(void*,int,int,int);
extern "C" void Combat_IncrementCappedEventCounter(unsigned char*,int);
extern "C" int Combat_HasSuperHighTension(void*);
extern "C" int Combatant_HasDamageRetaliationStatus(RecordForFlag18*);
// Original: arm9/ov024 @ 0x021E6948; symbol: func_ov024_021e6948; size: 0x148.
// Scales two amounts by eighths, indexed category multipliers, a mode-dependent random override and a halving flag.
extern "C" int Combat_ComputeFlagAdjustedEighthProduct(char* self,int index,int amount,int factor){
 float value=(float)amount*(float)factor/8.0f;
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),index);
 if(object){unsigned char category=*(unsigned char*)(*(char**)(object+0x138)+0x21);if(category<=3)value*=Combat_GetDamageStatusMultiplier((signed char)category);
 if(Combatant_HasDamageRetaliationStatus((RecordForFlag18*)object))value*=Combat_GetDamageStatusMultiplier(1);
 if(PartyRoster_ContainsActiveObjectIndex((unsigned char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv()),index)&&object&&*(unsigned char*)(*(char**)(object+0x138)+0x21)==1)Combat_IncrementCappedEventCounter(*(unsigned char**)(self+16),0);
 }
 if(value>0.0f&&Combat_TestMonsterDescriptorMode(*(void**)(self+16),index,0,1))value=(float)_Z13NextRandomMaxP6Randomi(*(void**)(self+16),2);
 if(Combat_HasSuperHighTension(object))value=0.5f*value;
 return (int)value;
}
