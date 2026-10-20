#include <globaldefs.h>
ARM
extern "C" char* Combat_GetPartyCharacterData(...);
extern "C" int Grotto_ReadBossOverrideOrSevenBitObjectValue(...);
extern "C" float _Z22NextRandomFloatBetweenP6Randomff(int,float,float);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};struct Vec {int x,y,z;};
// Original: arm9/ov024 @ 0x021DA168; symbol: Combat_ComputeSevenfoldRandomStatWithMinimum260; size: 0xe0.
// Scales selected party/boss stat with bounded random factor and applies independently randomized minimum.
extern "C" int Combat_ComputeSevenfoldRandomStatWithMinimum260(int* self,unsigned index,int unused1,int unused2,int unused3,int fallback){int valid=0;if(index<=3)valid=1;float base;if(valid){char* object=Combat_GetPartyCharacterData(*self,(short)index);if(!object)return fallback;unsigned value=H(object+2*W(object,0x950),0x16c);base=(float)value;}else base=(float)(int)Grotto_ReadBossOverrideOrSevenBitObjectValue((char*)*self,(short)index);int random=*self;float factor=_Z22NextRandomFloatBetweenP6Randomff(random,0.9f,1.1f);float value=(7.0f*base)*factor;float minimum=260.0f*_Z22NextRandomFloatBetweenP6Randomff(random,0.9f,1.1f);if(value<minimum)value=minimum;return (int)value;}
