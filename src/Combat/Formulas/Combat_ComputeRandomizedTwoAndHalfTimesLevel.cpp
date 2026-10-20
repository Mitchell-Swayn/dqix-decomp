#include <globaldefs.h>
ARM
extern "C" char* Combat_GetPartyCharacterData(void*,short);
extern "C" int Grotto_ReadBossOverrideOrSevenBitObjectValue(void*,short);
extern "C" float _Z22NextRandomFloatBetweenP6Randomff(void*,float,float);
// Original: arm9/ov024 @ 0x021D93DC; symbol: ScaleRandomizedPartyValueByTwoPointFive; size: 0xa0.
// Scales indexed party value by 2.5f and random factor0.9..1.1, returns fallback for missing party object.
extern "C" int Combat_ComputeRandomizedTwoAndHalfTimesLevel(void** context,unsigned index,int unused1,int unused2,int unused3,int fallback){
 float value;int party=0;if(index<=3)party=1;
 if(party){char* object=Combat_GetPartyCharacterData(*context,(short)index);if(!object)return fallback;
 value=*(unsigned short*)(object+0x16c+*(int*)(object+0x950)*2);
 }else value=Grotto_ReadBossOverrideOrSevenBitObjectValue(*context,(short)index);
 float factor=_Z22NextRandomFloatBetweenP6Randomff(*context,0.9f,1.1f);return (int)((2.5f*value)*factor);
}
