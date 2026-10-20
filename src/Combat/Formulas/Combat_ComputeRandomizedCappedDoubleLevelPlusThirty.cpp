#include <globaldefs.h>
ARM
extern "C" {char* Combat_GetPartyCharacterData(void*,short);int Grotto_ReadBossOverrideOrSevenBitObjectValue(void*,short);float _Z22NextRandomFloatBetweenP6Randomff(void*,float,float);}
// Original: arm9/ov024 @ 0x021D951C; symbol: ComputeRandomizedDoubleValueWith150Cap; size: 0xc4.
// Doubles indexed value plus30, caps150 and applies random plus/minus10 percent.
extern "C" int Combat_ComputeRandomizedCappedDoubleLevelPlusThirty(void** self,unsigned index,int unusedA,int unusedB,int unusedC,int fallback){float value;int party=0;if(index<=3)party=1;if(party){char* p=Combat_GetPartyCharacterData(*self,(short)index);if(!p)return fallback;value=(float)*(unsigned short*)(p+0x16c+2**(int*)(p+0x950));}else value=(float)Grotto_ReadBossOverrideOrSevenBitObjectValue(*self,(short)index);float base=30.0f+2.0f*value;if(base>150.0f)base=150.0f;float random=_Z22NextRandomFloatBetweenP6Randomff(*self,-0.1f,0.1f);return (int)(base+base*random);}
