#include <globaldefs.h>
struct State{int pad[12];int count;};
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_GetLocalMemberId(char*);
extern "C" void Network_UpdateMemberCountAndSessionTime(unsigned char*);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" bool Script_ExecuteFirstSatisfiedTriggerGroup(void*,int,State*);
extern "C" void Script_DispatchResultCommandsToWorld(State*);
extern "C" void FieldDialogue_ResetPeerResponseTracking(void*);
// Original: arm9/ov017 @ 0x021B9A98; symbol: func_ov017_021b9a98; size: 0x134.
// Counts peer replies and runs trigger group26 once a refusal or unanimous
// acceptance resolves the pending dialogue exchange.
extern "C" void FieldDialogue_ProcessPeerResponse(void* object,void* unused,unsigned member,unsigned unused2,unsigned short response){
 unsigned char* self=(unsigned char*)object;
 unsigned char* manager=(unsigned char*)Network_GetConnectionManager();
 int local=Network_GetLocalMemberId((char*)manager);
 if(member!=local&&member!=4)return;
 if(!self[0x130])return;
 Network_UpdateMemberCountAndSessionTime(manager);
 ++self[0x131];
 if(self[0x131]>=manager[0x100d]-1)self[0x130]=0;
 if(self[0x136])return;
 if(!response){
  self[0x133]=0;*(short*)(self+0x134)=*(int*)(self+0x12c);
  State result;
  if(Script_ExecuteFirstSatisfiedTriggerGroup(GameState_GetSerializedProgressState(),26,&result))Script_DispatchResultCommandsToWorld(&result);
  FieldDialogue_ResetPeerResponseTracking(self);self[0x136]=1;
 }else{
  ++self[0x132];
  if(self[0x132]>=manager[0x100d]-1){
   self[0x133]=1;*(short*)(self+0x134)=*(int*)(self+0x12c);
   State result;
   if(Script_ExecuteFirstSatisfiedTriggerGroup(GameState_GetSerializedProgressState(),26,&result))Script_DispatchResultCommandsToWorld(&result);
   FieldDialogue_ResetPeerResponseTracking(self);self[0x136]=1;
  }
 }
}
