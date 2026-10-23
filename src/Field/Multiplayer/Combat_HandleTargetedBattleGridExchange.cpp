#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct GridPacket{unsigned unknown;unsigned char member:4,response:1,remaining:3;unsigned char party[4],monsters[8];};
extern "C" {
int Network_GetLocalMemberId(char*);
void QueueOptionalCombatantByteLists(int,int);
void GameObject_SetBattleGridIndex(int,int);
unsigned FieldBattle_GetScene(void*);
void BattleScene_EnableFlags(unsigned char*,unsigned);
}
// Original: arm9/ov017 @ 0x021C82BC; symbol: Combat_HandleTargetedBattleGridExchange; size: 0xDC.
extern "C" void Combat_HandleTargetedBattleGridExchange(int kind,GridPacket* packet,void* unused,unsigned char* resources,char* network){
if(Network_GetLocalMemberId(network)!=packet->member)return;
if(packet->response){QueueOptionalCombatantByteLists((unsigned char)kind,0);return;}
GameState* game=GameState::GetInstance();
for(int i=0;i<4;++i){GameObject* object=game->GetCombatantByIndex(i);if(object&&packet->party[i]!=0xff)GameObject_SetBattleGridIndex((int)object,packet->party[i]);}
for(int i=0;i<8;++i){GameObject* object=game->GetCombatantByIndex(i+0xc0);if(object&&packet->monsters[i]!=0xff)GameObject_SetBattleGridIndex((int)object,packet->monsters[i]);}
unsigned scene=FieldBattle_GetScene(*(void**)(resources+0x3718));if(scene)BattleScene_EnableFlags((unsigned char*)scene,0x200000);
}
