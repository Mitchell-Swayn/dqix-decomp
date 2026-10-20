#include <globaldefs.h>
ARM
struct Descriptor;
extern "C" int GameObject_GetCombatTrackingRecord(int);
extern "C" int Grotto_ApplyPositiveSlotDescriptor(Descriptor*,unsigned short*,unsigned char*,int);
extern "C" int GameState_SelectLowestRatioGroupObject(unsigned char**,int,int,short*);
extern "C" void BattleAI_EvaluateAvailableActionsByCategory(void*);
// Original: arm9/ov024 @ 0x021F84F0; symbol: func_ov024_021f84f0; size: 0x138.
// Tries ranked descriptor lists in context-dependent priority order, then selects the lowest-ratio group object.
extern "C" void Combat_ApplyRankedDescriptorPrioritiesOrLowestRatio(char* self,int unused,int object,short* output){
 int data=GameObject_GetCombatTrackingRecord(object);if(!data)return;
 *(float*)(self+0x124)=0.25f;BattleAI_EvaluateAvailableActionsByCategory(self);
 if(Grotto_ApplyPositiveSlotDescriptor((Descriptor*)(self+0x4c8),(unsigned short*)output,(unsigned char*)data,*(short*)(self+4)))return;
 if(Grotto_ApplyPositiveSlotDescriptor((Descriptor*)(self+0x498),(unsigned short*)output,(unsigned char*)data,*(short*)(self+4)))return;
 if(*(int*)(self+12)>=4&&Grotto_ApplyPositiveSlotDescriptor((Descriptor*)(self+0x528),(unsigned short*)output,(unsigned char*)data,*(short*)(self+4)))return;
 if(*(int*)(self+12)>=2){if(Grotto_ApplyPositiveSlotDescriptor((Descriptor*)(self+0x3a8),(unsigned short*)output,(unsigned char*)data,*(short*)(self+4)))return;if(Grotto_ApplyPositiveSlotDescriptor((Descriptor*)(self+0x408),(unsigned short*)output,(unsigned char*)data,*(short*)(self+4)))return;}
 else{if(Grotto_ApplyPositiveSlotDescriptor((Descriptor*)(self+0x3d8),(unsigned short*)output,(unsigned char*)data,*(short*)(self+4)))return;if(Grotto_ApplyPositiveSlotDescriptor((Descriptor*)(self+0x438),(unsigned short*)output,(unsigned char*)data,*(short*)(self+4)))return;}
 GameState_SelectLowestRatioGroupObject((unsigned char**)self,unused,object,output);
}
