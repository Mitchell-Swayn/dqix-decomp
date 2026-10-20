#include <globaldefs.h>
ARM
struct LinkedDescriptorView;
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int CombatEffect_TargetHasParalysis(LinkedDescriptorView*);
extern "C" void CombatStatus_ClearParalysis(unsigned char*);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
struct Mask{unsigned low,high;};
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,Mask,int);
struct PackedCodes{unsigned low:10,middle:10,high:10,rest:2;};
struct Marker{unsigned char set:1,rest:7;};struct Flag{unsigned char low:7,set:1;};
// Original: arm9/ov024 @ 0x021DD6F0; symbol: func_ov024_021dd6f0; size: 0x138.
// Clears linked flag8 when enabled, selects success/failure feedback and builds a result record.
extern "C" void* Combat_ClearLinkedFlag8AndBuildResult(char* self,int unused,int target,char* descriptor,int unused4,int unused5,unsigned char enabled){
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),target);if(!object)return 0;
 Mask mask;mask.low=0;mask.high=0;unsigned short code;
 if(CombatEffect_TargetHasParalysis((LinkedDescriptorView*)object)&&enabled){code=Combat_SelectMessageForPartyOrMonster(target,((PackedCodes*)(descriptor+32))->high,((PackedCodes*)(descriptor+36))->low);CombatStatus_ClearParalysis(*(unsigned char**)(object+0x138));Combat_SetResultMaskFlag(*(void**)(self+16),(unsigned long long*)&mask,0x1a);((Marker*)(*(char**)(object+0x138)+0x3b))->set=1;++*(int*)(self+20);}
 else code=Combat_SelectMessageForPartyOrMonster(target,((PackedCodes*)(descriptor+36))->middle,((PackedCodes*)(descriptor+36))->high);
 void* record=Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(self+16));if(!record)return 0;
 Combat_AppendResultMessage(*(void**)(self+16),record,code);
 Combat_PopulateResultWithCurrentHealthAndMagic(*(void**)(self+16),record,object,0,mask,((Flag*)(*(char**)(self+12)+0x1c))->set!=0);
 return record;
}
