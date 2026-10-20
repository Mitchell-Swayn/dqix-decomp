#include <globaldefs.h>
ARM
struct Record;struct Owner;
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" int GameState_AddCombatantValueUpToMaximum(void*,int,unsigned short,unsigned short*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultFromCombatantSnapshot(void*,Record*,Owner*,short,short,short,void*,void*,unsigned char);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
struct Mask{unsigned low,high;};
struct PackedCodes{unsigned low:10,middle:10,high:10,rest:2;};
struct FlagByte{unsigned char low:7,flag:1;};
struct Nested {unsigned short first,current,pad,maximum;unsigned ReadFirst(){return first;}unsigned ReadCurrent(){return current;}unsigned ReadMaximum(){return maximum;}};
struct DescriptorCode{unsigned value:12,rest:20;unsigned short Read(){return value;}};
static inline int IsParty(int id){return id>=0&&id<=3;}
// Original: arm9/ov024 @ 0x021DDF5C; symbol: func_ov024_021ddf5c; size: 0x1C8.
// Restores a combatant value, chooses descriptor feedback and builds a result record; two action codes use the target maximum.
extern "C" void* Combat_RestoreValueAndBuildDescriptorResult(char* self,int unused,int target,char* descriptor,int amount){
 char* recipient=_Z16GetCombatantByIDii(*(int*)(self+16),target);if(!recipient)return 0;
 unsigned short action=((DescriptorCode*)(descriptor+4))->Read();
 if(action==0x19b||action==0x22e)amount=*(unsigned short*)(*(char**)(recipient+0x138)+6);
 short applied=0;
 int result=((int(*)(void*,int,int,unsigned short*))GameState_AddCombatantValueUpToMaximum)(*(void**)(self+16),target,amount,(unsigned short*)&applied);
 int excess=0;if(!IsParty(target)&&*(unsigned short*)(*(char**)(recipient+0x138)+2)>=255)excess=1;
 unsigned short code;
 if(applied>0||excess){code=Combat_SelectMessageForPartyOrMonster(target,((PackedCodes*)(descriptor+32))->high,((PackedCodes*)(descriptor+36))->low);++*(int*)(self+20);}
 else code=Combat_SelectMessageForPartyOrMonster(target,((PackedCodes*)(descriptor+36))->middle,((PackedCodes*)(descriptor+36))->high);
 void* record=Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(self+16));if(!record)return 0;
 Combat_AppendResultMessage(*(void**)(self+16),record,code);
 Mask mask;mask.low=0;mask.high=0;Combat_SetResultMaskFlag(*(void**)(self+16),(unsigned long long*)&mask,0x22);
 unsigned char flag=((FlagByte*)(*(char**)(self+12)+0x1c))->flag!=0;
 short detail=((Nested*)*(char**)(recipient+0x138))->ReadFirst();
 ((void(*)(void*,void*,void*,short,short,int,Mask,unsigned char))Combat_PopulateResultFromCombatantSnapshot)(*(void**)(self+16),record,recipient,(short)-applied,detail,result,mask,flag);
 return record;
}
