#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned* GameResources_GetInstance();
extern "C" char* Network_GetConnectionManager();
extern "C" char* Network_GetReceivedMemberPacket(char*,int);
extern "C" void* Network_GetCommandRecordPool();
extern "C" unsigned Network_TestMemberDisconnectFlag(char*,int);
extern "C" unsigned Network_GetConnectionState();
extern "C" unsigned* SystemState_GetGlobalFlags();
extern "C" void SystemState_ClearFlags(unsigned*,unsigned);
extern "C" void* NavigationMessage_GetGlobalInstance();
extern "C" void NavigationMessage_ResetAndEnable(void*);
extern "C" int NavigationMessage_EnqueueWithFormattedMemberName(unsigned char*,short,int,signed char);
extern "C" int Network_GetLocalMemberId(char*);
extern "C" int Network_IsMemberConnected(unsigned,int);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" void GameResources_SetPrimaryFlags(unsigned*,unsigned);
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(void*);
extern "C" void Field_ResetActivePartyJoinRequest(char*);
extern "C" void GameState_ResetPartyMemberHalfwords(void*);
extern "C" void* Network_EnableAllIncomingRecordTypes(unsigned char*);
extern "C" void GameResources_ClearPrimaryFlags(unsigned*,unsigned);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
struct RecordBits {unsigned short first:1,rest:15;};
// Original: arm9/ov017 @ 0x021AF2F8; symbol: func_ov017_021af2f8; size: 0x1F4.
extern "C" unsigned Network_UpdateDisconnectSelectionState(char* self) {
 _ZN9GameState11GetInstanceEv();
 unsigned* resources=GameResources_GetInstance();
 char* conn=Network_GetConnectionManager();
 Network_GetReceivedMemberPacket(conn,0);
 void* bits=Network_GetCommandRecordPool();
 if(Network_TestMemberDisconnectFlag(conn,0)||Network_GetConnectionState()==8) {
  SystemState_ClearFlags(SystemState_GetGlobalFlags(),0x8020);
  void* display=NavigationMessage_GetGlobalInstance();
  NavigationMessage_ResetAndEnable(display);
  NavigationMessage_EnqueueWithFormattedMemberName((unsigned char*)display,4,-1,0);
  return 3;
 }
 int available=0;
 if(Network_GetLocalMemberId(conn)==0)available=1;
 else {
  for(int i=0;i<4;i++) {
   if(i==Network_GetLocalMemberId(conn))continue;
   if(!Network_IsMemberConnected((unsigned)conn,i))continue;
   char* record=Network_GetReceivedMemberPacket(conn,i);
   if(record && !((RecordBits*)(record+2))->first) {available=1;break;}
  }
  if(*(signed char*)(self+0x10)!=Network_GetLocalMemberId(conn))self[0xf]=0;
 }
 int mode=*(signed char*)(self+0xf);
 if(mode==-1||available) {
  if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)) {
   self[0xf]=-1;
   GameResources_SetPrimaryFlags(resources,2);
   WaitForStateThreeThenProcessOwnerWithTimeout(conn);
   Field_ResetActivePartyJoinRequest((char*)resources);
   GameState_ResetPartyMemberHalfwords(resources);
   Network_EnableAllIncomingRecordTypes((unsigned char*)bits);
   GameResources_ClearPrimaryFlags(resources,0x40);
   self[1]=1;
  }
 } else if(mode==1) {
  if(!*(int*)(conn+0xfc0))self[1]=1;
 } else {
  GameResources_SetPrimaryFlags(resources,2);
  WaitForStateThreeThenProcessOwnerWithTimeout(conn);
  Field_ResetActivePartyJoinRequest((char*)resources);
  GameState_ResetPartyMemberHalfwords(resources);
  Network_EnableAllIncomingRecordTypes((unsigned char*)bits);
  GameResources_ClearPrimaryFlags(resources,0x40);
  self[1]=1;
 }
 return *(unsigned char*)(self+8);
}
