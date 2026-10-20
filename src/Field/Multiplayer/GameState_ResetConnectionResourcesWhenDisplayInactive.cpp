#include <globaldefs.h>
ARM
struct Owner; struct A; struct GameResources;
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void* NavigationMessage_GetGlobalInstance();
extern "C" bool NavigationMessage_TestDisabledOrEmpty(A*);
extern "C" void SystemState_SetFlags(unsigned*,unsigned);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* Network_GetConnectionManager();
extern "C" void* Network_GetCommandRecordPool();
extern "C" void GameResources_SetPrimaryFlags(unsigned*,unsigned);
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(Owner*);
extern "C" void Field_ResetActivePartyJoinRequest(char*);
extern "C" void GameState_ResetPartyMemberHalfwords(GameResources*);
extern "C" void NavigationMessage_DisableAndCancelLoading(unsigned char*);
extern "C" void* Network_EnableAllIncomingRecordTypes(unsigned char*);
extern "C" void GameResources_ClearPrimaryFlags(unsigned*,unsigned);
// Original: arm9/ov017 @ 0x021AF4EC; symbol: func_ov017_021af4ec; size: 0xB0.
extern "C" unsigned GameState_ResetConnectionResourcesWhenDisplayInactive(unsigned char* self) {
 void* global=SystemState_GetGlobalFlags();
 void* display=NavigationMessage_GetGlobalInstance();
 if(NavigationMessage_TestDisabledOrEmpty((A*)display)) {
  SystemState_SetFlags((unsigned*)global,0x20);
  GameResources* resources=GameResources_GetInstance();
  void* connection=Network_GetConnectionManager();
  void* queue=Network_GetCommandRecordPool();
  self[15]=0;
  GameResources_SetPrimaryFlags((unsigned*)resources,2);
  WaitForStateThreeThenProcessOwnerWithTimeout((Owner*)connection);
  Field_ResetActivePartyJoinRequest((char*)resources);
  GameState_ResetPartyMemberHalfwords(resources);
  NavigationMessage_DisableAndCancelLoading((unsigned char*)display);
  Network_EnableAllIncomingRecordTypes((unsigned char*)queue);
  GameResources_ClearPrimaryFlags((unsigned*)resources,0x40);
  ((unsigned char*)resources)[0x42e3]=0;
  ((unsigned char*)resources)[0x42e2]=0;
  self[1]=1;
 }
 return self[8];
}
