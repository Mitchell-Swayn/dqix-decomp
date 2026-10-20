#include <globaldefs.h>
ARM
struct Lists;struct Node;struct Record;struct Owner;
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" short Combat_AddHealthUpToMaximum(void*,int,int,short*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultFromCombatantSnapshot(void*,Record*,Owner*,short,short,short,void*,void*,unsigned char);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_AppendActorResultToCategoryList(char*,void*,int);
extern "C" Node* Combat_GetTargetResultByCategoryAndPosition(Lists*,int,int);
extern "C" void* Combat_GetIndexedActionTarget(void*,int);
struct Mask{unsigned low,high;};
struct Descriptor{unsigned low:12;unsigned high:20;};
// Original: arm9/ov024 @ 0x021E5988; symbol: func_ov024_021e5988; size: 0x170.
// Sums linked signed values, applies a quarter as restoration, and queues a descriptor record with the applied amount.
extern "C" void Combat_RestoreQuarterOfLinkedValuesAndQueueRecord(char* self,int index,char* descriptor){
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),index);if(!object)return;
 char* entries=*(char**)(self+12);
 if(((Descriptor*)(descriptor+4))->low==0x91){void* alternate=Combat_GetIndexedActionTarget(*(void**)(self+4),0);if(alternate)entries=(char*)alternate;}
 int sum=0;for(int i=0;i<*(unsigned char*)(entries+0x18);i++){char* node=(char*)Combat_GetTargetResultByCategoryAndPosition((Lists*)entries,i,0);if(node)sum+=*(short*)(node+12);}
 sum>>=2;if(sum<=0)return;
 short applied=0;
 short code=Combat_AddHealthUpToMaximum(*(void**)(self+16),index,sum,&applied);
 *(short*)(*(char**)(self+8)+0x22)=code;
 void* record=Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(self+16));if(!record)return;
 Mask mask;mask.low=0;mask.high=0;Combat_SetResultMaskFlag(*(void**)(self+16),(unsigned long long*)&mask,0x25);
 Combat_AppendResultMessage(*(void**)(self+16),record,0x215);
 short detail=*(volatile short*)(*(char**)(object+0x138)+2);
 ((void(*)(void*,void*,void*,short,short,short,Mask,unsigned char))Combat_PopulateResultFromCombatantSnapshot)(*(void**)(self+16),record,object,(short)-sum,code,detail,mask,0);
 Combat_AppendActorResultToCategoryList(*(char**)(self+8),record,2);
 ++*(unsigned char*)(*(char**)(self+16)+0x8e02);
}
