#include <globaldefs.h>
ARM
struct Owner;
extern "C" bool CombatStatus_CanAdjustCharmStage(unsigned char*,int);
extern "C" int CombatStatus_AdjustCharmStageAndRefreshTimer(Owner*,int);
extern "C" void _Z20UpdateCombatantCharmii(int,int);
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
struct Mask{unsigned low,high;};struct Flags;
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,Mask,int);
extern "C" void Combat_SuppressMessageForExceptionalOutcome(void*,Flags*,unsigned short*);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
struct PackedCodes{unsigned low:10,middle:10,high:10,rest:2;};struct Flag{unsigned char low:7,set:1;};
// Original: arm9/ov024 @ 0x021E0380; symbol: func_ov024_021e0380; size: 0x160.
// Adjusts the charm stage and emits special feedback when a positive delta reaches stage two.
extern "C" void* Combat_AdjustCharmStageAndBuildResult(char* self,int unused,int target,char* descriptor,int unused4,int unused5,unsigned char enabled){
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),target);if(!object)return 0;
 int applied=0,result=0;
 if(enabled){int delta=*(short*)(descriptor+0x30);if(delta<-2)delta=-2;if(delta>2)delta=2;int direction=0;if(delta<0)direction=1;if(((bool(*)(unsigned char*,unsigned char))CombatStatus_CanAdjustCharmStage)(*(unsigned char**)(object+0x138),direction)){result=CombatStatus_AdjustCharmStageAndRefreshTimer(*(Owner**)(object+0x138),(signed char)delta);_Z20UpdateCombatantCharmii(*(int*)(self+16),target);applied=1;}}
 unsigned short code=0;
 if(applied){if(*(short*)(descriptor+0x30)>0){if(result==2)code=0xf7;}}else code=Combat_SelectMessageForPartyOrMonster(target,((PackedCodes*)(descriptor+36))->middle,((PackedCodes*)(descriptor+36))->high);
 void* record=Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(self+16));if(!record)return 0;
 Combat_SuppressMessageForExceptionalOutcome(self,*(Flags**)(self+12),&code);Combat_AppendResultMessage(*(void**)(self+16),record,code);
 ((void(*)(void*,void*,void*,int,unsigned long long,int))Combat_PopulateResultWithCurrentHealthAndMagic)(*(void**)(self+16),record,object,0,0ULL,((Flag*)(*(char**)(self+12)+0x1c))->set!=0);return record;
}
