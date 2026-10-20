#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" char* Combat_GetPartyCharacterData(int,int);extern "C" int Grotto_ReadBossOverrideOrSevenBitObjectValue(int,int);extern "C" float _Z22NextRandomFloatBetweenP6Randomff(void*,float,float);
// Original: arm9/ov024 @ 0x021D90C8; symbol: ComputeRandomizedDoublePartyValuePlus125; size: 0xac.
extern "C" int Combat_ComputeRandomizedDoubleLevelPlus125(int* self,unsigned index,int unused,int unused2,int unused3,int fallback){
float value;int valid=0;if(index<=3)valid=1;if(valid){char* object=Combat_GetPartyCharacterData(*self,(short)index);if(!object)return fallback;value=(unsigned)*(unsigned short*)(object+0x16c+W(object,0x950)*2);}else value=Grotto_ReadBossOverrideOrSevenBitObjectValue(*self,(short)index);float random=_Z22NextRandomFloatBetweenP6Randomff((void*)*self,0.85f,1.15f);return (int)((125.f+2.f*value)*random);
}
