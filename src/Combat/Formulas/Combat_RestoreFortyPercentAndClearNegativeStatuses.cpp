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
extern "C" int _Z7RoundUpf(float);
extern "C" int Combat_ClearNegativeStatusesAndReapplyBuffs(char*,int);
// Original: arm9/ov024 @ 0x021E13E0; symbol: func_ov024_021e13e0; size: 0x1A0.
// Restores forty percent of maximum (at least75), clears negative statuses, and emits combined restoration/cleansing feedback.
extern "C" void* Combat_RestoreFortyPercentAndClearNegativeStatuses(char* self,int unused,int target){
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),target);if(!object)return 0;
 int amount=_Z7RoundUpf(0.4f*(float)(unsigned)*(unsigned short*)(*(char**)(object+0x138)+4));
 if(amount<75)amount=75;Mask mask;mask.low=0;mask.high=0;short applied=0;
 short result=Combat_AddHealthUpToMaximum(*(void**)(self+16),target,amount,&applied);
 void* record=Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(self+16));if(!record)return 0;
 int found=0;
 if(applied>0){Combat_SetResultMaskFlag(*(void**)(self+16),(unsigned long long*)&mask,0x25);Combat_AppendResultMessage(*(void**)(self+16),record,0x1ba);Combat_AppendResultMessage(*(void**)(self+16),record,0x16);found=1;}
 if(Combat_ClearNegativeStatusesAndReapplyBuffs(self,target)>0){if(!found){Combat_AppendResultMessage(*(void**)(self+16),record,0x1ba);found=1;}Combat_AppendResultMessage(*(void**)(self+16),record,0x1bb);}
 if(!found)Combat_AppendResultMessage(*(void**)(self+16),record,0x1f);
 unsigned char flag=((FlagByte*)(*(char**)(self+12)+0x1c))->flag!=0;
 short detail=((Nested*)*(char**)(object+0x138))->ReadCurrent();
 ((void(*)(void*,void*,void*,short,short,short,Mask,unsigned char))Combat_PopulateResultFromCombatantSnapshot)(*(void**)(self+16),record,object,(short)-applied,result,detail,mask,flag);
 return record;
}
