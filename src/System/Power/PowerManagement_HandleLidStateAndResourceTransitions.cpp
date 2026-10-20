#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void*);
extern "C" int SystemState_TestAnyFlags(void*,unsigned);
extern "C" void Sound_SetMasterVolumeForPowerTransition(int);
extern "C" void PM_GoSleepMode(int,int,int);
extern "C" int CardReadManager_ReadGlobalStatus();
extern "C" void IPC_SendNormalizedBooleanModeCommand(int);
extern "C" int PowerManagement_IsLcdPowerEnabled();
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void Graphics_WriteMainAndSubPolygonAttributes(GameResources*);
extern "C" void ResetUnknownObjectStateForSelectedCodes(GameResources*);
// Original: arm9/main @ 0x02012DE8; symbol: func_02012de8; size: 0x114.
extern "C" void PowerManagement_HandleLidStateAndResourceTransitions(){
 void* resource=SystemState_GetGlobalFlags();void* zone=Network_GetConnectionManager();
 if((int)(*(volatile unsigned short*)0x027fffa8&0x8000)>>15){
  if((!Network_IsSessionActive(zone)||SystemState_TestAnyFlags(resource,0x1000000))&&!SystemState_TestAnyFlags(resource,0x80)){
   Sound_SetMasterVolumeForPowerTransition(0);PM_GoSleepMode(12,0,0);if(CardReadManager_ReadGlobalStatus())return;Sound_SetMasterVolumeForPowerTransition(127);return;
  }
  if(!SystemState_TestAnyFlags(resource,0x400000))IPC_SendNormalizedBooleanModeCommand(0);
  if(!Network_IsSessionActive(zone)||SystemState_TestAnyFlags(resource,0x1000000))return;
  GameResources* game=GameState_ReadPResources(GameState::GetInstance());if(!game)return;ResetUnknownObjectStateForSelectedCodes(game);return;
 }
 if(PowerManagement_IsLcdPowerEnabled())return;IPC_SendNormalizedBooleanModeCommand(1);GameResources* game=GameState_ReadPResources(GameState::GetInstance());if(!game)return;Graphics_WriteMainAndSubPolygonAttributes(game);
}
