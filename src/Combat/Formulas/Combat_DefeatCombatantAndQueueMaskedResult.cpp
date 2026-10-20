#include <globaldefs.h>
ARM
extern "C" int Combat_AppendActorResultToCategoryList(...);
extern "C" int Combat_ClearCurrentResultNodeSlot(...);
extern "C" int Combat_AppendResultMessage(...);
extern "C" int Combat_SetResultMaskFlag(...);
extern "C" int _Z16GetCombatantByIDii(...);
extern "C" int Combat_SubtractHealthAndRecordProtagonistDefeat(...);
extern "C" int Combat_AppendResultMessage(...);
extern "C" int Combat_PopulateResultWithCurrentHealthAndMagic(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021E5AF8; symbol: AppendMaskedCombatantEntry279.
extern "C" void Combat_DefeatCombatantAndQueueMaskedResult(char*self,int key,int extra){
char*object=C(_Z16GetCombatantByIDii(W(self,16),key));if(!object)return;int current=Combat_ClearCurrentResultNodeSlot(P(self,16));if(!current)return;unsigned long long mask=0;Combat_SubtractHealthAndRecordProtagonistDefeat(P(self,16),key,key,65535,&mask,extra,0,16);mask=0;Combat_SetResultMaskFlag(P(self,16),&mask,13);Combat_AppendResultMessage(P(self,16),current,279);Combat_PopulateResultWithCurrentHealthAndMagic(P(self,16),current,object,0,(unsigned)mask,(unsigned)(mask>>32),0);Combat_AppendActorResultToCategoryList(P(self,8),current,2);B(P(self,16),0x8e02)++;
}
