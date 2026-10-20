#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" bool CombatStatus_CanApplyConfusion(unsigned*);
extern "C" void CombatStatus_ApplyConfusion(char*);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
struct Mask{unsigned low,high;};struct Flags;
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,Mask,int);
extern "C" void Combat_SuppressMessageForExceptionalOutcome(void*,Flags*,unsigned short*);
extern "C" int Combat_SelectConfusionMessage(char*,int,int);
extern "C" int Combat_CanReplaceAilmentFlags(void*,unsigned,unsigned);
struct Flag{unsigned char low:7,set:1;};
// Original: arm9/ov024 @ 0x021DD828; symbol: func_ov024_021dd828; size: 0x140.
// Resets nested mode fields and sets flag20 when allowed, recording reset and optional blocked-bit effects.
extern "C" void* Combat_ResetModeFieldsAndBuildResult(char* self,int unused,int target,char* descriptor,int unused4,int unused5,unsigned char enabled){
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),target);if(!object)return 0;
 int success=0;if(CombatStatus_CanApplyConfusion(*(unsigned**)(object+0x138))&&enabled)success=1;else *(unsigned char*)(self+0x75)=0;
 unsigned short code=Combat_SelectConfusionMessage(self,target,success);
 Mask mask;mask.low=0;mask.high=0;
 if(success){if(Combat_CanReplaceAilmentFlags(self,*(unsigned*)(*(char**)(object+0x138)+20),0x20))Combat_SetResultMaskFlag(*(void**)(self+16),(unsigned long long*)&mask,0x2b);CombatStatus_ApplyConfusion(*(char**)(object+0x138));Combat_SetResultMaskFlag(*(void**)(self+16),(unsigned long long*)&mask,0x17);++*(int*)(self+20);}
 void* record=Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(self+16));if(!record)return 0;
 Combat_SuppressMessageForExceptionalOutcome(self,*(Flags**)(self+12),&code);Combat_AppendResultMessage(*(void**)(self+16),record,code);
 Combat_PopulateResultWithCurrentHealthAndMagic(*(void**)(self+16),record,object,0,mask,((Flag*)(*(char**)(self+12)+0x1c))->set!=0);return record;
}
