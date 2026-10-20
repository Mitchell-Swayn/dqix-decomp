#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct Fields{char pad[0x16c];unsigned short levels[1];};
extern "C" char* Combat_GetPartyCharacterData(void*,int);extern "C" int Grotto_ReadBossOverrideOrSevenBitObjectValue(void*,int);extern "C" float _Z22NextRandomFloatBetweenP6Randomff(void*,float,float);
// Original: arm9/ov024 @ 0x021DA328; symbol: ComputeRandomizedValueWithDoubledRecordMinimum; size: 0xDC.
extern "C" int Combat_ComputeRandomizedDoubleLevelWithFloor35(void** self,unsigned index,int a,int b,int unused,int fallback){int party=0;if(index<=3)party=1;float value;if(party){char* object=Combat_GetPartyCharacterData(*self,(short)index);if(!object)return fallback;value=(float)((Fields*)object)->levels[W(object,0x950)];}else value=(float)Grotto_ReadBossOverrideOrSevenBitObjectValue(*self,(short)index);void* random=*self;float first=35.0f*_Z22NextRandomFloatBetweenP6Randomff(random,0.85f,1.15f);float roll=_Z22NextRandomFloatBetweenP6Randomff(random,0.85f,1.15f);float second=(2.0f*value)*roll;if(first<second)first=second;return (int)first;}
