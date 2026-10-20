#include <globaldefs.h>
ARM
struct Record;struct Owner;
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultFromCombatantSnapshot(void*,Record*,Owner*,short,short,short,void*,void*,unsigned char);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
struct Mask{unsigned low,high;};
struct PackedCodes{unsigned low:10,middle:10,high:10,rest:2;};
struct FlagByte{unsigned char low:7,flag:1;};
struct Nested {unsigned short first,current,pad,maximum;unsigned ReadFirst(){return first;}unsigned ReadCurrent(){return current;}unsigned ReadMaximum(){return maximum;}};
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" int PartyRoster_ContainsActiveObjectIndex(unsigned char*,unsigned);
extern "C" void Combat_IncrementCappedEventCounter(unsigned char*,int);
extern "C" int Combat_SubtractHealthAndRecordProtagonistDefeat(void*,int,int,int,unsigned*,int,unsigned char,int);
extern "C" short Combat_AddHealthUpToMaximum(void*,int,int,short*);
struct DescriptorCode{unsigned value:12,rest:20;};
struct Values {unsigned short current,other,maximum;unsigned Current(){return current;}unsigned Maximum(){return maximum;}};
// Original: arm9/ov024 @ 0x021DC700; symbol: func_ov024_021dc700; size: 0x23C.
// Transfers health while leaving the donor alive and constructs restoration feedback for the recipient.
extern "C" void* Combat_TransferHealthAndBuildRestorationResult(char* self,int source,int target,char* descriptor,int amount,int unused,unsigned char enabled){
 char* donor=_Z16GetCombatantByIDii(*(int*)(self+16),source);if(!donor)return 0;
 char* recipient=_Z16GetCombatantByIDii(*(int*)(self+16),target);if(!recipient)return 0;
 Values* values=(Values*)*(char**)(recipient+0x138);unsigned maximum=values->Maximum(),current=values->Current();
 if(current>=maximum)amount=0;
 unsigned available=((Values*)*(char**)(donor+0x138))->Current();
 if(available<=1)amount=0;if(target==source)amount=0;if(amount>(int)available)amount=available-1;
 unsigned short code;
 if(enabled&&amount>0){code=Combat_SelectMessageForPartyOrMonster(target,((PackedCodes*)(descriptor+32))->high,((PackedCodes*)(descriptor+36))->low);
 if(PartyRoster_ContainsActiveObjectIndex((unsigned char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv()),source)&&((Values*)*(char**)(recipient+0x138))->Current()==1&&((DescriptorCode*)(descriptor+4))->value==0xb7)Combat_IncrementCappedEventCounter(*(unsigned char**)(self+16),2);
 }else{amount=0;code=Combat_SelectMessageForPartyOrMonster(target,((PackedCodes*)(descriptor+36))->middle,((PackedCodes*)(descriptor+36))->high);*(unsigned char*)(self+0x6d)=0;}
 void* record=Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(self+16));if(!record)return 0;
 Combat_AppendResultMessage(*(void**)(self+16),record,code);
 Mask mask;mask.low=0;mask.high=0;
 Combat_SubtractHealthAndRecordProtagonistDefeat(*(void**)(self+16),source,source,amount,(unsigned*)&mask,(int)descriptor,((FlagByte*)(*(char**)(self+12)+0x1c))->flag!=0,0);
 mask.low=0;mask.high=0;short applied=0;
 short result=Combat_AddHealthUpToMaximum(*(void**)(self+16),target,amount,&applied);
 Combat_SetResultMaskFlag(*(void**)(self+16),(unsigned long long*)&mask,0x25);
 unsigned char flag=((FlagByte*)(*(char**)(self+12)+0x1c))->flag!=0;
 short detail=((Nested*)*(char**)(recipient+0x138))->ReadCurrent();
 ((void(*)(void*,void*,void*,short,short,short,Mask,unsigned char))Combat_PopulateResultFromCombatantSnapshot)(*(void**)(self+16),record,recipient,(short)-applied,result,detail,mask,flag);
 return record;
}
