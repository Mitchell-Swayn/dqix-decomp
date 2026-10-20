#include <globaldefs.h>
ARM
extern "C" int CombatStatus_CanAdjustShieldBlockStage(int*,int);
extern "C" int CombatStatus_AdjustShieldBlockStageAndRefreshDuration(char*,int);
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
struct Mask{unsigned low,high;};
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,Mask,int);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
struct PackedCodes{unsigned low:10,middle:10,high:10,rest:2;};struct Flag{unsigned char low:7,set:1;};
// Original: arm9/ov024 @ 0x021DED48; symbol: func_ov024_021ded48; size: 0x13C.
// Applies a clamped signed stage-eight delta when enabled and emits success/failure descriptor feedback.
extern "C" void* Combat_AdjustPackedStageEightAndBuildResult(char* self,int unused,int target,char* descriptor,int unused4,int unused5,unsigned char enabled){
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),target);if(!object)return 0;
 int applied=0;
 if(enabled){int delta=*(short*)(descriptor+0x30);if(delta<-2)delta=-2;if(delta>2)delta=2;int direction=0;if(delta<0)direction=1;if(((int(*)(int*,unsigned char))CombatStatus_CanAdjustShieldBlockStage)(*(int**)(object+0x138),direction)){CombatStatus_AdjustShieldBlockStageAndRefreshDuration(*(char**)(object+0x138),(signed char)delta);applied=1;}}
 unsigned short code;
 if(applied)code=Combat_SelectMessageForPartyOrMonster(target,((PackedCodes*)(descriptor+32))->high,((PackedCodes*)(descriptor+36))->low);else code=Combat_SelectMessageForPartyOrMonster(target,((PackedCodes*)(descriptor+36))->middle,((PackedCodes*)(descriptor+36))->high);
 void* record=Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(self+16));if(!record)return 0;
 Combat_AppendResultMessage(*(void**)(self+16),record,code);
 ((void(*)(void*,void*,void*,int,unsigned long long,int))Combat_PopulateResultWithCurrentHealthAndMagic)(*(void**)(self+16),record,object,0,0ULL,((Flag*)(*(char**)(self+12)+0x1c))->set!=0);return record;
}
