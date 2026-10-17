#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" void* Object_GetGlobalConnectionState();extern "C" int IsFirstWordNonzero(),TestInactiveOrPrimaryIndexState(void*),Object_TestIndexedByte100EFlagByKey(void*,unsigned),GameState_IsFlagAtOffset441CZero(void*);extern "C" void Record_SetActiveByteWhenModeEnabled(void*),Network_QueuePartyAction(int,unsigned char);
// Original: arm9/main @ 0x020E35A0; symbol: func_020e35a0; size: 0x124.
extern "C" void SynchronizePartyRequestAndAcknowledgmentFlags(unsigned char* flags){GameState* state=GameState::GetInstance();void* service=GameResources_GetInstance();void* party=Object_GetGlobalConnectionState();if(!IsFirstWordNonzero())return;if(TestInactiveOrPrimaryIndexState(party)){if(GameState_IsFlagAtOffset441CZero(service)){for(int i=0;i<4;++i)if(flags[0]&(1<<i)){if(i==0)Record_SetActiveByteWhenModeEnabled(flags);else Network_QueuePartyAction(1,(unsigned char)i);}flags[1]|=flags[0];flags[0]=0;}for(int i=1;i<4;++i)if(!state->GetGameObjectByIndex(i)||Object_TestIndexedByte100EFlagByKey(party,i)){unsigned mask=~(1<<i);flags[0]&=mask;flags[1]&=mask;}}else if(Object_TestIndexedByte100EFlagByKey(party,0))flags[2]=1;}
