#include <globaldefs.h>
ARM
struct Record;struct Owner;
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultFromCombatantSnapshot(void*,Record*,Owner*,short,short,short,void*,void*,unsigned char);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
struct Mask{unsigned low,high;};
struct PackedCodes{unsigned low:10,middle:10,high:10,rest:2;};
struct FlagByte{unsigned char low:7,flag:1;};
struct Nested {unsigned short first,current,pad,maximum;unsigned ReadFirst(){return first;}unsigned ReadCurrent(){return current;}unsigned ReadMaximum(){return maximum;}};
struct LinkedDescriptorView;struct A;
extern "C" int CombatEffect_TargetHasParalysis(LinkedDescriptorView*);
extern "C" void CombatStatus_ClearParalysis(unsigned char*);
extern "C" int CombatStatus_HasAilmentModeOne(Record*);
extern "C" int CombatStatus_HasAilmentModeTwo(A*);
extern "C" void CombatStatus_ClearAilmentModeOne(char*);
extern "C" short Combat_AddHealthUpToMaximum(void*,int,int,short*);
struct ByteFlag {unsigned char set:1,high:7;};
struct Values{unsigned short current,other,maximum;unsigned Current(){return current;}unsigned Maximum(){return maximum;}};
// Original: arm9/ov024 @ 0x021E2784; symbol: func_ov024_021e2784; size: 0x1CC.
// Restores a linked halfword and clears two descriptor conditions, recording each applied change in an effect mask.
extern "C" void* Combat_RestoreLinkedValueAndClearDescriptorConditions(char* self,int unused,int target,char* descriptor,int amount){
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),target);if(!object)return 0;
 void* record=Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(self+16));if(!record)return 0;
 Mask mask;mask.low=0;mask.high=0;
 short result=*(short*)(*(char**)(object+0x138));short applied=0;
 Values* values=(Values*)*(char**)(object+0x138);unsigned maximum=values->Maximum(),current=values->Current();
 if(current<maximum){result=Combat_AddHealthUpToMaximum(*(void**)(self+16),target,amount,&applied);Combat_SetResultMaskFlag(*(void**)(self+16),(unsigned long long*)&mask,0x25);Combat_AppendResultMessage(*(void**)(self+16),record,0x16);++*(int*)(self+20);}
 if(CombatEffect_TargetHasParalysis((LinkedDescriptorView*)object)){
 CombatStatus_ClearParalysis(*(unsigned char**)(object+0x138));
 ((ByteFlag*)(*(char**)(object+0x138)+0x3b))->set=1;
 Combat_SetResultMaskFlag(*(void**)(self+16),(unsigned long long*)&mask,0x1a);Combat_AppendResultMessage(*(void**)(self+16),record,0x1f9);++*(int*)(self+20);}
 if(CombatStatus_HasAilmentModeOne(*(Record**)(object+0x138))||CombatStatus_HasAilmentModeTwo(*(A**)(object+0x138))){
 CombatStatus_ClearAilmentModeOne(*(char**)(object+0x138));Combat_SetResultMaskFlag(*(void**)(self+16),(unsigned long long*)&mask,0x11);Combat_AppendResultMessage(*(void**)(self+16),record,0x54);++*(int*)(self+20);}
 unsigned char flag=((FlagByte*)(*(char**)(self+12)+0x1c))->flag!=0;
 short detail=((Nested*)*(char**)(object+0x138))->ReadCurrent();
 ((void(*)(void*,void*,void*,short,short,short,Mask,unsigned char))Combat_PopulateResultFromCombatantSnapshot)(*(void**)(self+16),record,object,(short)-applied,result,detail,mask,flag);
 return record;
}
