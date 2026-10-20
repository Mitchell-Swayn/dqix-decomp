#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
void *GameState_GetObjectWithFlag100(GameState *,int);short *GameObject_GetLinkedStatsOrNull(void *);
// Original: arm9/main @ 0x020DD718; symbol: func_020dd718; size: 0x50.
bool Party_TestValueAmongTenMemberHalfwords(int i,int v){short *q=GameObject_GetLinkedStatsOrNull(GameState_GetObjectWithFlag100(GameState::GetInstance(),i));for(unsigned char j=0;j<10;j++)if(q[j]==v)return true;return false;}
}
