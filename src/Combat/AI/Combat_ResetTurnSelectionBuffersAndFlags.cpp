#include <globaldefs.h>
ARM
extern "C" void* memset(...);
extern "C" int BattleAI_InitializeRankedActionChoices(...);
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov024 @ 0x021F73B8; symbol: Combat_ResetTurnSelectionBuffersAndFlags; size: 0xc0.
// Combat ResetTurnSelectionBuffersAndFlags from listed field operations and calls.
extern "C" void Combat_ResetTurnSelectionBuffersAndFlags(char* self){W(self,0x74)=0;W(self,0x78)=0;W(self,0x9c)=0;for(int i=0;i<3;++i)*(unsigned*)(self+4*i+0xb8)=0;memset(self+0xe4,0,32);W(self,0x174)=0;BattleAI_InitializeRankedActionChoices(self+0x378);memset(self+0x10,0,21);B(self,7)=0;B(self,0x139)=0;memset(self+0x104,0,16);memset(self+0x114,0,16);memset(self+0x44,0,16);memset(self+0x13c,0,24);memset(self+0x154,0,24);}
