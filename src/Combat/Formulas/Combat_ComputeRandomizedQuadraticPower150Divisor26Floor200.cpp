#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" char* Combat_GetPartyCharacterData(void*,int);extern "C" unsigned Grotto_ReadBossOverrideOrSevenBitObjectValue(char*,unsigned);extern "C" float _Z22NextRandomFloatBetweenP6Randomff(void*,float,float);inline int IsParty(unsigned index){int yes=0;if(index<=3)yes=1;return yes;}
// Original: arm9/ov024 @ 0x021D9F70; symbol: Combat_ComputeRandomizedQuadraticPower150Divisor26Floor200; size: 0x110.
extern "C" int Combat_ComputeRandomizedQuadraticPower150Divisor26Floor200(char** self,int index,int unused2,int unused3,int unused4,int fallback){
float result;void* random;float value;if(IsParty(index)){char* member=Combat_GetPartyCharacterData(*self,(short)index);if(!member)return fallback;value=(unsigned)*(unsigned short*)(member+0x16c+*(int*)(member+0x950)*2);}else value=(int)Grotto_ReadBossOverrideOrSevenBitObjectValue(*self,(short)index);
random=*self;float base=150.0f+value*(value/26.0f);result=base+base*_Z22NextRandomFloatBetweenP6Randomff(random,-0.1f,0.1f);float minimum=200.0f*_Z22NextRandomFloatBetweenP6Randomff(random,0.95f,1.05f);if(result<minimum)result=minimum;return (int)result;
}
