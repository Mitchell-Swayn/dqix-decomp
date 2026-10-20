#include <globaldefs.h>
ARM
extern "C" void BattleAI_EvaluateAvailableActionsByCategory(void*);
extern "C" int Grotto_ApplyPositiveSlotDescriptor(void*,void*,void*,int);
extern "C" int GameState_SelectLowestRatioGroupObject(void*,int,int,void*);
extern "C" int GameObject_GetCombatTrackingRecord(int);
// Original: arm9/ov024 @ 0x021F8144; symbol: Combat_TryTwoSlotDescriptorsThenSelectRatioGroup; size: 0x98.
extern "C" void BattleAI_SelectEmergencyHealingOrDamageAction(char* self,int unused,int object,void* output) {
 int data=GameObject_GetCombatTrackingRecord(object);if(!data)return;*(int*)(self+0x170)=0;*(float*)(self+0x124)=0.08f;BattleAI_EvaluateAvailableActionsByCategory(self);
 if(Grotto_ApplyPositiveSlotDescriptor(self+0x4c8,output,(void*)data,*(short*)(self+4)))return;
 if(Grotto_ApplyPositiveSlotDescriptor(self+0x408,output,(void*)data,*(short*)(self+4)))return;
 GameState_SelectLowestRatioGroupObject(self,unused,object,output);
}
