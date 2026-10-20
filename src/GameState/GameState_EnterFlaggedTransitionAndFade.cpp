#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <Resource/Brightness.h>
extern "C" GameResources* GameResources_GetInstance();extern "C" void Field_EndMultiplayerSessionAndRestoreLocalParty();extern "C" void* SystemState_GetGlobalFlags();extern "C" int SystemState_TestAnyFlags(void*,unsigned);extern "C" void SystemState_SetFlags(void*,unsigned);extern "C" int WaitForStatusWithTimeoutAndSleep(unsigned*,int);extern "C" void GameState_RequestSaveErrorExit(GameState*);
// Original: arm9/main @ 0x0202B1F4; symbol: func_0202b1f4; size: 0x90.
extern "C" int GameState_EnterFlaggedTransitionAndFade(unsigned* object){GameState* state=GameState::GetInstance();GameResources* resources=GameResources_GetInstance();void* flags=SystemState_GetGlobalFlags();if(SystemState_TestAnyFlags(flags,0x1000000))return 3;int result=WaitForStatusWithTimeoutAndSleep(object,1);if((unsigned char)(result+0xfe)>1)return result;SystemState_SetFlags(flags,0x1000000);Field_EndMultiplayerSessionAndRestoreLocalParty();SetBrightness(resources,-16,10);((unsigned char*)state)[0x5cc8]=4;GameState_RequestSaveErrorExit(state);*object=3;return 3;}
