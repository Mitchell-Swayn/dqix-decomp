#include <globaldefs.h>
ARM
struct Descriptor { unsigned short id;signed char type;unsigned char pad;float value;unsigned short unknown;unsigned char first,second;};
extern "C" int GameObject_GetCombatTrackingRecord(int);
extern "C" void BattleAI_EvaluateAvailableActionsByCategory(void*);
extern "C" int Grotto_ApplyPositiveSlotDescriptor(Descriptor*,unsigned short*,unsigned char*,int);
extern "C" int GameState_SelectLowestRatioGroupObject(unsigned char**,int,int,short*);
// Original: arm9/ov024 @ 0x021F8300; symbol: Grotto_ApplyFirstPositiveDescriptorOrLowestRatio; size: 0xf8.
// Tries five positive descriptor slots before selecting a lowest-ratio group object.
extern "C" int Grotto_ApplyFirstPositiveDescriptorOrLowestRatio(char *self,int unused,int object,short *result){
 int status;unsigned char *out=(unsigned char*)GameObject_GetCombatTrackingRecord(object);if(!out)return (int)out;
 *(float*)(self+0x124)=0.4f;BattleAI_EvaluateAvailableActionsByCategory(self);
 if((status=Grotto_ApplyPositiveSlotDescriptor((Descriptor*)(self+0x4c8),(unsigned short*)result,out,*(short*)(self+4))))return status;
 if((status=Grotto_ApplyPositiveSlotDescriptor((Descriptor*)(self+0x498),(unsigned short*)result,out,*(short*)(self+4))))return status;
 if(*(int*)(self+12)>=4&&(status=Grotto_ApplyPositiveSlotDescriptor((Descriptor*)(self+0x528),(unsigned short*)result,out,*(short*)(self+4))))return status;
 if((status=Grotto_ApplyPositiveSlotDescriptor((Descriptor*)(self+0x3a8),(unsigned short*)result,out,*(short*)(self+4))))return status;
 if((status=Grotto_ApplyPositiveSlotDescriptor((Descriptor*)(self+0x438),(unsigned short*)result,out,*(short*)(self+4))))return status;
 return GameState_SelectLowestRatioGroupObject((unsigned char**)self,unused,object,result);
}
