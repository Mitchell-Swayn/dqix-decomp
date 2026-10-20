#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" int BattleMenu_HasCommandBlockingStatus(void*);
// Original: arm9/ov000 @ 0x02180A64; symbol: GameState_ResetCountersWhenAllMappedRecordsAreTypeSix; size: 0xd8.
extern "C" void BattleMenu_StartTransitionWhenAllPartyCommandsAreReady(unsigned char* self){unsigned char* base;int total=0,ready=0;base=self+0x958;unsigned char* record;for(int i=0;i<4;++i){record=base+((signed char*)self+i)[0x6c]*0x448;if(W(record,0x4c)>=0&&!BattleMenu_HasCommandBlockingStatus(record)){++total;if(((signed char*)record+((signed char*)record)[24])[16]>=100&&((signed char*)record)[28]==6)++ready;}}if(total!=ready)return;W(self,0x920)=256;W(self,0x924)=256;W(self,0x928)=256;W(self,0x910)=0;W(self,0x914)=0;W(self,0x918)=0;W(self,0x91c)=0;U(self,0x1d72)&=~8;U(self,0x1d72)&=~16;U(self,0x1d72)|=32;}
