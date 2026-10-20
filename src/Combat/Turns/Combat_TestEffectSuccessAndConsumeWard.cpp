#include <globaldefs.h>
ARM
struct Effect {
 unsigned pad0;
 unsigned id:12,lower:10,upper:10;
 unsigned pad8:8,kind:2,rest8:22;
 unsigned padc,flags;
 unsigned fixed:7,low:7,high:7,rest14:11;
 unsigned pad18:16,mode:2,rest18:9,attribute:5;
};
struct Attrs {unsigned pad[4];unsigned a:10,b:10,c:10,d:2;};
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
unsigned char* GameState_GetObjectWithFlag100(void*,int);
int _Z13NextRandomMaxP6Randomi(void*,int);
float _Z22NextRandomFloatBetweenP6Randomff(void*,float,float);
int CharacterState_WeaponGuaranteesQualifyingActionSuccess(char*);
int CharacterState_WeaponCanFailQualifyingActions(char*);
void CombatantState_ClearSchizofanic(int);
void CombatantState_ClearMistMe(int);
int Combat_TestMonsterDescriptorMode(void*,int,int,int);
int Combat_HasKnightWatch(void*);
int Combat_HasSoulAsylum(void*);
int Combat_HasAccuracyImpairmentStatus(void*);
float Combat_ComputeClampedAttributeModifier(void*,int,int);
}
// Original: arm9/ov000 @ 0x02156648; symbol: func_ov000_02156648; size: 0x4A8.
extern "C" int Combat_TestEffectSuccessAndConsumeWard(unsigned char* self,int source,int target,unsigned char* report,Effect* effect,unsigned char* outcome,unsigned char force) {
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned char* object=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),target);
 self[0x8e95]=0;
 if(effect->id!=0x150){
   if(object && Combat_HasKnightWatch(object) && effect->kind==1){report[0x1c]|=0x40;return 0;}
   if(object && Combat_HasSoulAsylum(object) && effect->kind==1){report[0x1c]|=0x20;return 0;}
 }
 if((effect->flags&0x40) && object){
   unsigned flags=*(unsigned*)(*(unsigned char**)(object+0x138)+0x14);
   if(flags&0x100000){outcome[10]|=8;report[0x1c]|=8;CombatantState_ClearSchizofanic(*(int*)(object+0x138));return 0;}
   if(flags&0x200000){outcome[10]|=16;report[0x1c]|=16;CombatantState_ClearMistMe(*(int*)(object+0x138));return 0;}
 }
 if(force)return 1;
 if(Combat_TestMonsterDescriptorMode(self,target,0,1) && !(effect->flags&0x1000000))return 0;
 float chance=100.0f;
 int random=_Z13NextRandomMaxP6Randomi(self,100);
 bool party;
 if(source>=0 && source<=3)party=true;else party=false;
 if(party){
   unsigned char* attacker=GameState_GetObjectWithFlag100(state,source);
   if(!attacker)return 0;
   if((effect->flags&0x40000) && CharacterState_WeaponGuaranteesQualifyingActionSuccess(*(char**)(attacker+0x150)))return 1;
   if((effect->flags&0x10000) && CharacterState_WeaponCanFailQualifyingActions(*(char**)(attacker+0x150)) && _Z13NextRandomMaxP6Randomi(self,4)==0)return 0;
 }
 if(effect->mode==1){
   if(source>=0 && source<=3)party=true;else party=false;
   if(party){
     unsigned char* attacker=GameState_GetObjectWithFlag100(state,source);
     if(!attacker)return 0;
     Attrs* stats=*(Attrs**)(attacker+0x138);
     unsigned short a=stats->b,b=stats->c;
     unsigned value=0;
     bool selected=false;
     if(effect->flags&0x4000){value=a;selected=true;}
     else if(effect->flags&0x8000){value=b;selected=true;}
     if(selected){
       if(value<=effect->lower)chance=(float)effect->low;
       else if(value>=effect->upper)chance=(float)effect->high;
       else chance=(float)(effect->low+(int)((float)(value-effect->lower)*((float)(effect->high-effect->low)/(float)(effect->upper-effect->lower))));
     }else chance=(float)(int)_Z22NextRandomFloatBetweenP6Randomff(self,(float)effect->low,(float)effect->high);
   }else chance=(float)effect->fixed;
   float modifier=Combat_ComputeClampedAttributeModifier(self,target,effect->attribute);
   if(modifier>0.0f){
     if(outcome[10]&1)return 1;
     if(modifier<1.0f)self[0x8e95]=1;
     if(chance<100.0f)self[0x8e95]=1;
   }
   chance=0.5f+chance*modifier;
 }
 if((effect->flags&8) && Combat_HasAccuracyImpairmentStatus(_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),source)) && _Z13NextRandomMaxP6Randomi(self,8)<5)return 0;
 return random<(int)chance;
}
