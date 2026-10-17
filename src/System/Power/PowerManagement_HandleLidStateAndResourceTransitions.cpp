#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" void* GetGlobalStatePointer();
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int IsFirstWordNonzero(void*);
extern "C" int TestWordMaskNonzero(void*,unsigned);
extern "C" void SubmitOperationCodeTwentyThree(int);
extern "C" void func_020ce89c(int,int,int);
extern "C" int CardReadManager_ReadGlobalStatus();
extern "C" void IPC_SendNormalizedBooleanModeCommand(int);
extern "C" int PowerManagement_IsLcdPowerEnabled();
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void Graphics_WriteMainAndSubPolygonAttributes(GameResources*);
extern "C" void func_ov017_02199e98(GameResources*);
// Original: arm9/main @ 0x02012DE8; symbol: func_02012de8; size: 0x114.
extern "C" void PowerManagement_HandleLidStateAndResourceTransitions(){
 void* resource=GetGlobalStatePointer();void* zone=Object_GetGlobalConnectionState();
 if((int)(*(volatile unsigned short*)0x027fffa8&0x8000)>>15){
  if((!IsFirstWordNonzero(zone)||TestWordMaskNonzero(resource,0x1000000))&&!TestWordMaskNonzero(resource,0x80)){
   SubmitOperationCodeTwentyThree(0);func_020ce89c(12,0,0);if(CardReadManager_ReadGlobalStatus())return;SubmitOperationCodeTwentyThree(127);return;
  }
  if(!TestWordMaskNonzero(resource,0x400000))IPC_SendNormalizedBooleanModeCommand(0);
  if(!IsFirstWordNonzero(zone)||TestWordMaskNonzero(resource,0x1000000))return;
  GameResources* game=GameState_ReadPResources(GameState::GetInstance());if(!game)return;func_ov017_02199e98(game);return;
 }
 if(PowerManagement_IsLcdPowerEnabled())return;IPC_SendNormalizedBooleanModeCommand(1);GameResources* game=GameState_ReadPResources(GameState::GetInstance());if(!game)return;Graphics_WriteMainAndSubPolygonAttributes(game);
}
