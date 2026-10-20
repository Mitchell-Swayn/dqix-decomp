#include <globaldefs.h>
#include <Util/Random.h>
ARM
extern "C" int Combat_GetPartyCharacterData(void*,int);
extern "C" unsigned Grotto_ReadBossOverrideOrSevenBitObjectValue(char*,unsigned);
#pragma always_inline on
inline bool IsPartyIndexUnsigned(unsigned index){bool result=false;if(index<=3)result=true;return result;}
// Original: arm9/ov024 @ 0x021D9C7C; symbol: func_ov024_021d9c7c; size: 0xF0.
// Randomizes a selected object value and returns the larger of its scaled result and a randomized 200-unit floor.
extern "C" int Combat_ComputeRandomizedSelectedValueWithFloor(char** context,unsigned index,int unused2,int unused3,int unused4,int fallback){
 float attribute;
 if(IsPartyIndexUnsigned(index)){
  unsigned char* object=(unsigned char*)Combat_GetPartyCharacterData(*context,(short)index);
  if(!object)return fallback;
  attribute=(float)(unsigned)*(unsigned short*)(object+0x16c+*(int*)(object+0x950)*2);
 }else attribute=(float)(int)Grotto_ReadBossOverrideOrSevenBitObjectValue(*context,(short)index);
 Random* random=(Random*)*context;
 float sample=NextRandomFloatBetween(random,0.9f,1.1f);
 float value=(50.0f+5.0f*attribute)*sample;
 float floor=200.0f*NextRandomFloatBetween(random,0.9f,1.1f);
 if(value<floor)value=floor;
 return (int)value;
}
