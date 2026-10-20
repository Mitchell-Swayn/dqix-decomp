#include <globaldefs.h>
ARM
struct LinkedDescriptorView;
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" int Combat_HasOrdinaryTension(LinkedDescriptorView*);
extern "C" int Combat_HasSuperHighTension(void*);
extern "C" void CombatStatus_DecrementTensionStage(unsigned char*);
extern "C" void* GameState_CreateAndAppendIndexedRecord(void*,unsigned);
struct Mask{unsigned low,high;};
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,Mask,int);
// Original: arm9/ov024 @ 0x021E373C; symbol: func_ov024_021e373c; size: 0x130.
// Decrements a flagged target state, selects its transition feedback and returns the transition effect mask.
extern "C" unsigned long long Combat_DecrementFlaggedTargetStateAndRecordTransition(char* self,int unused,int target,int unused3,int amount){
 if(amount<=0)return 0;
 char* object=_Z16GetCombatantByIDii(*(int*)(self+16),target);if(!object)return 0;
 if(!Combat_HasOrdinaryTension((LinkedDescriptorView*)object)&&!Combat_HasSuperHighTension(object))return 0;
 CombatStatus_DecrementTensionStage(*(unsigned char**)(object+0x138));
 unsigned code;unsigned state;state=*(unsigned char*)(*(char**)(object+0x138)+0x24);code=0;
 switch(state){case 0:code=0x17f;break;case 1:code=0x180;break;case 2:code=0x181;break;case 3:code=0x259;break;}
 Mask mask;mask.low=0;mask.high=0;
 Combat_SetResultMaskFlag(*(void**)(self+16),(unsigned long long*)&mask,0x1d);
 if(state==3)Combat_SetResultMaskFlag(*(void**)(self+16),(unsigned long long*)&mask,8);
 void* record=GameState_CreateAndAppendIndexedRecord(self,code);
 if(record)Combat_PopulateResultWithCurrentHealthAndMagic(*(void**)(self+16),record,object,0,mask,0);
 return *(unsigned long long*)&mask;
}
