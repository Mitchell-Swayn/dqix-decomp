#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_TestMonsterDescriptorMode(void*,int,int,int);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
extern "C" void CombatantState_ClearFatalDamageProtection(unsigned char*);
extern "C" int Combatant_HasFatalDamageProtection(unsigned char*);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" int Combat_SubtractHealthAndRecordProtagonistDefeat(void*,int,int,int,unsigned*,int,unsigned char,int);
struct Nested{char pad[0x48];unsigned char rate;int Rate(){return rate;}};
struct Health{unsigned short value;unsigned Read(){return value;}};
struct FlagByte{unsigned char low:7,flag:1;};
// Original: arm9/ov024 @ 0x021E4604; symbol: func_ov024_021e4604; size: 0x1D8.
// Rolls an indexed effect chance, then reduces health to one or applies the defeat path and returns its two-word effect mask.
extern "C" unsigned long long Combat_RollHealthReductionOrDefeat(char* self,int source,int target,int reason){
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),target);
 if(!Combat_TestMonsterDescriptorMode(*(void**)(self+16),target,0,1)&&((Nested*)*(char**)(object+0x138))->Rate()<=0)return 0;
 int roll=_Z13NextRandomMaxP6Randomi(*(void**)(self+16),100);
 float chance=12.5f;
 if(!Combat_TestMonsterDescriptorMode(*(void**)(self+16),target,0,1))chance=12.5f*((float)((Nested*)*(char**)(object+0x138))->Rate()/100.0f);
 if(((FlagByte*)(*(char**)(self+12)+0x1c))->flag)chance=100.0f;
 if((float)roll>=chance)return 0;
 unsigned long long mask=0;
 if(Combatant_HasFatalDamageProtection((unsigned char*)object)){
 CombatantState_ClearFatalDamageProtection(*(unsigned char**)(object+0x138));
 unsigned char notify=((FlagByte*)(*(char**)(self+12)+0x1c))->flag!=0;unsigned health=((Health*)*(char**)(object+0x138))->Read();
 Combat_SubtractHealthAndRecordProtagonistDefeat(*(void**)(self+16),source,target,health-1,(unsigned*)&mask,reason,notify,0);
 Combat_SetResultMaskFlag(*(void**)(self+16),&mask,0x29);
 }else{
 Combat_SubtractHealthAndRecordProtagonistDefeat(*(void**)(self+16),source,target,65535,(unsigned*)&mask,reason,((FlagByte*)(*(char**)(self+12)+0x1c))->flag!=0,8);
 mask=0;Combat_SetResultMaskFlag(*(void**)(self+16),&mask,0xd);
 }
 return mask;
}
