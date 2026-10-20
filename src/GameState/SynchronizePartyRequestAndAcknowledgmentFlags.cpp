#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" void* Network_GetConnectionManager();extern "C" int Network_IsSessionActive(),Network_IsParentOrOffline(void*),Network_TestMemberDisconnectFlag(void*,unsigned),Field_IsPartyJoinRequestIdle(void*);extern "C" void Network_MarkLocalPartySynchronizationReady(void*),Network_QueuePartyAction(int,unsigned char);
// Original: arm9/main @ 0x020E35A0; symbol: func_020e35a0; size: 0x124.
extern "C" void SynchronizePartyRequestAndAcknowledgmentFlags(unsigned char* flags){GameState* state=GameState::GetInstance();void* service=GameResources_GetInstance();void* party=Network_GetConnectionManager();if(!Network_IsSessionActive())return;if(Network_IsParentOrOffline(party)){if(Field_IsPartyJoinRequestIdle(service)){for(int i=0;i<4;++i)if(flags[0]&(1<<i)){if(i==0)Network_MarkLocalPartySynchronizationReady(flags);else Network_QueuePartyAction(1,(unsigned char)i);}flags[1]|=flags[0];flags[0]=0;}for(int i=1;i<4;++i)if(!state->GetGameObjectByIndex(i)||Network_TestMemberDisconnectFlag(party,i)){unsigned mask=~(1<<i);flags[0]&=mask;flags[1]&=mask;}}else if(Network_TestMemberDisconnectFlag(party,0))flags[2]=1;}
