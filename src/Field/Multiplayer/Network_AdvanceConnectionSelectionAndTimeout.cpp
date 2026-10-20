#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameResources_GetInstance();
extern "C" char* Network_GetConnectionManager();
extern "C" char* Network_GetCommandRecordPool();
extern "C" int Network_GetLocalMemberId(char*);
extern "C" char* Network_GetReceivedMemberPacket(char*,int);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" void GameResources_SetPrimaryFlags(unsigned*,unsigned);
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(char*);
extern "C" void Field_ResetActivePartyJoinRequest(char*);
extern "C" void GameState_ResetPartyMemberHalfwords(char*);
extern "C" void* Network_EnableAllIncomingRecordTypes(unsigned char*);
extern "C" void GameResources_ClearPrimaryFlags(unsigned*,unsigned);
extern "C" unsigned Network_TestMemberDisconnectFlag(char*,int);
extern "C" unsigned Network_GetConnectionState();
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_ClearFlags(unsigned*,unsigned);
extern "C" unsigned char* NavigationMessage_GetGlobalInstance();
extern "C" void NavigationMessage_ResetAndEnable(void*);
extern "C" int NavigationMessage_EnqueueWithFormattedMemberName(unsigned char*,short,int,signed char);
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void Network_ActivateMember(unsigned char*,int);
extern "C" void* Network_DisableAllIncomingRecordTypes(char*);
extern "C" void Network_EnableIncomingRecordType(unsigned char*,unsigned);
extern "C" void Network_QueueProtagonistNameRecord();
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
#define CLEANUP() GameResources_SetPrimaryFlags((unsigned*)resources,2);WaitForStateThreeThenProcessOwnerWithTimeout(connection);Field_ResetActivePartyJoinRequest(resources);GameState_ResetPartyMemberHalfwords(resources);Network_EnableAllIncomingRecordTypes((unsigned char*)global);GameResources_ClearPrimaryFlags((unsigned*)resources,0x40);*(unsigned char*)(self+1)=1
// Original: arm9/ov017 @ 0x021AF098; symbol: func_ov017_021af098; size: 0x260.
extern "C" int Network_AdvanceConnectionSelectionAndTimeout(char* self){
 void* state=_ZN9GameState11GetInstanceEv();
 char* resources=GameResources_GetInstance();
 char* connection=Network_GetConnectionManager();
 char* global=Network_GetCommandRecordPool();
 if(Network_GetLocalMemberId(connection)==0){
  Network_GetReceivedMemberPacket(connection,0);
  if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)){
   *(signed char*)(self+15)=-1;CLEANUP();
  }else{
   if(Network_TestMemberDisconnectFlag(connection,0) || Network_GetConnectionState()==8){
    SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(),0x8020);
    unsigned char* display=NavigationMessage_GetGlobalInstance();NavigationMessage_ResetAndEnable(display);NavigationMessage_EnqueueWithFormattedMemberName(display,4,-1,0);return 3;
   }
   *(unsigned short*)(self+18)+=_ZNK9GameState21GetEffectiveDeltaTimeEv(state);
   if(*(unsigned short*)(self+18)>5000){*(unsigned char*)(self+15)=0;CLEANUP();return *(unsigned char*)(self+8);}
  }
  return *(unsigned char*)(self+8);
 }
 if(Network_GetLocalMemberId(connection)>=4){*(unsigned char*)(self+15)=0;CLEANUP();return *(unsigned char*)(self+8);}
 *(unsigned char*)(self+16)=Network_GetLocalMemberId(connection);
 int selected=Network_GetLocalMemberId(connection);Network_ActivateMember((unsigned char*)connection,selected);
 GameResources_ClearPrimaryFlags((unsigned*)resources,2);Network_DisableAllIncomingRecordTypes(global);
 Network_EnableIncomingRecordType((unsigned char*)global,44);Network_EnableIncomingRecordType((unsigned char*)global,42);Network_EnableIncomingRecordType((unsigned char*)global,46);Network_EnableIncomingRecordType((unsigned char*)global,61);Network_EnableIncomingRecordType((unsigned char*)global,51);
 Network_QueueProtagonistNameRecord();*(unsigned short*)(self+18)=0;
 return 2;
}
