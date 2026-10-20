#include <globaldefs.h>
ARM
struct Eight {short values[8];};struct Triple {int x,y,z;};
extern "C" int BattleMenu_AdvanceCommandWindowTransition(...);
extern "C" int BattleMenu_SelectNextPartyCommandAndResetTransition(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov000 @ 0x0218099C; symbol: GameState_UpdateSelectedSlotStateFromRecordFlag; size: 0xc8.
// GameState UpdateSelectedSlotStateFromRecordFlag from listed field operations and calls.
extern "C" void BattleMenu_UpdateTransitionForSelectedPartyCommand(char* self,void* argument){for(int i=0;i<4;++i){char* record=self+0x958+*(signed char*)(self+0x6c+i)*0x448;if(W(self,0x17c)==W(record,0x4c)){if(!(B(record,0x24)&4)){if(!BattleMenu_SelectNextPartyCommandAndResetTransition(self))return;BattleMenu_AdvanceCommandWindowTransition(self,argument,0);H(self,0x1d72)&=~8;H(self,0x1d72)=(H(self,0x1d72)|16)&~32;return;}W(self,0x910)=0;W(self,0x914)=0;W(self,0x918)=0;W(self,0x91c)=0;H(self,0x1d72)&=~0x38;return;}}}
