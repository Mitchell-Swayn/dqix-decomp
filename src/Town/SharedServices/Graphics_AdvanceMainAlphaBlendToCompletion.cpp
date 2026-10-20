#include <globaldefs.h>
ARM
struct Eight {short values[8];};struct Triple {int x,y,z;};
extern "C" char* GameResources_GetInstance(...);
extern "C" int ColorEffect_ConfigureAlphaBlend(...);
extern "C" int GameResources_SetSecondaryFlags(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov003 @ 0x0216EF14; symbol: Graphics_AdvanceMainAlphaBlendToCompletion; size: 0xc8.
// Graphics AdvanceMainAlphaBlendToCompletion from listed field operations and calls.
extern "C" void Graphics_AdvanceMainAlphaBlendToCompletion(char* self){void* resources=GameResources_GetInstance();if(B(self,0x3b)>=16){B(self,0x3b)=16;ColorEffect_ConfigureAlphaBlend(0x4000050,4,8,12,4);*(volatile unsigned*)0x4000000=(*(volatile unsigned*)0x4000000&~0x1f00)|0x1f00;GameResources_SetSecondaryFlags(resources,0xcce);H(self,0x20)|=32;B(self,1)=4;B(self,2)=0;return;}B(self,0x3b)+=4;if(B(self,0x3b)>16){B(self,0x3b)=16;GameResources_SetSecondaryFlags(resources,0xcce);}unsigned alpha=B(self,0x3b);ColorEffect_ConfigureAlphaBlend(0x4000050,24,1,alpha,16-alpha);}
