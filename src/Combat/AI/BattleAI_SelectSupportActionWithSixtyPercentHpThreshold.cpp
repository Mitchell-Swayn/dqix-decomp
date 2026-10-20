#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {unsigned char* GameObject_GetCombatTrackingRecord(void*);void BattleAI_EvaluateAvailableActionsByCategory(void*);int Grotto_ApplyPositiveSlotDescriptor(void*,void*,void*,int);int GameState_SelectLowestRatioGroupObject(void*,int,void*,void*);}
// Original: arm9/ov024 @ 0x021F83F8; symbol: Grotto_ApplyFirstEligibleSlotOrSelectRatioGroup; size: 0xf8.
// Tests ordered slot descriptors before falling back to lowest-ratio group selection.
extern "C" void BattleAI_SelectSupportActionWithSixtyPercentHpThreshold(unsigned char* self,int unused,void* object,void* output){unsigned char* record=GameObject_GetCombatTrackingRecord(object);if(!record)return;*(float*)(self+0x124)=0.6f;BattleAI_EvaluateAvailableActionsByCategory(self);if(Grotto_ApplyPositiveSlotDescriptor(self+0x4c8,output,record,H(self,4)))return;if(Grotto_ApplyPositiveSlotDescriptor(self+0x498,output,record,H(self,4)))return;if(W(self,12)>=2){if(Grotto_ApplyPositiveSlotDescriptor(self+0x528,output,record,H(self,4)))return;if(Grotto_ApplyPositiveSlotDescriptor(self+0x3d8,output,record,H(self,4)))return;}if(Grotto_ApplyPositiveSlotDescriptor(self+0x438,output,record,H(self,4)))return;GameState_SelectLowestRatioGroupObject(self,unused,object,output);}
