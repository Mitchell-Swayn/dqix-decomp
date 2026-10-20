#include <globaldefs.h>
ARM
extern "C" char* Combat_GetPartyCharacterData(int,int);
extern "C" int Grotto_ReadBossOverrideOrSevenBitObjectValue(int,int);
// Original: arm9/ov024 @ 0x021D96D0; symbol: ComputeQuarterPartyValuePlusFive; size: 0x7c.
// Converts indexed party value to one quarter plus five, retaining fallback for absent objects.
extern "C" int Combat_ComputeQuarterLevelPlusFive(int* self,unsigned index,int unused,int unused2,int unused3,int fallback) {
 float value;
 int valid=0; if(index<=3)valid=1;
 if(valid){char* p=Combat_GetPartyCharacterData(*self,(short)index);if(!p)return fallback;value=(unsigned int)*(unsigned short*)(p+0x16c+*(int*)(p+0x950)*2);}
 else value=Grotto_ReadBossOverrideOrSevenBitObjectValue(*self,(short)index);
 return (int)(5.0f+value/4.0f);
}
