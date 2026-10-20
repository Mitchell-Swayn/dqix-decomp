#include <globaldefs.h>
ARM
struct StatusPayload { unsigned char a,b,c; unsigned char index:2,unknown:1,mode:2,flag:1,pad:2; unsigned short global,field6,field8; unsigned short fieldA; unsigned short fieldC,fieldE; };
struct StatusPacket { unsigned char type; char pad[3]; StatusPayload payload; };
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* Network_GetConnectionManager();
unsigned char* Zone3D_GetMainInstance();
unsigned char* GameResources_GetInstance();
void* Network_GetCommandRecordPool();
bool Network_IsParentOrOffline(void*);
int GameState_GetProgressChapter(void*);
int GameState_ReadUnknown5cb4(void*);
int GameState_ReadUnknownCb8(void*);
unsigned char* FieldBattle_GetCombatContext(void*);
unsigned char* FieldBattle_GetEncounterRequest(void*);
int FieldEvent_IsQueuedOrSynchronizing(unsigned char*);
void Network_QueueOutgoingRecord(void*,const void*,short);
}
inline StatusPayload* StatusData(StatusPacket* p) { return &p->payload; }
struct PrimaryStatus { char gap0[0x12]; unsigned char flags; char gap13[3]; unsigned short f16,f18,f1a,f1c; char gap1e[0x34]; short f52; char gap54[0x48]; unsigned char inactive; };
inline PrimaryStatus* GetPrimary(unsigned char* p) { return *(PrimaryStatus**)(p+0x3734); }
inline unsigned char* GetSecondary(unsigned char* p) { return *(unsigned char**)(p+0x3718); }
inline unsigned char* GetExtra(unsigned char* p) { return *(unsigned char**)(p+0x3b30); }
// Original: arm9/ov017 @ 0x021D0490; symbol: func_ov017_021d0490; size: 0x20C.
extern "C" void GameState_QueueObjectAndResourceStatus(int index) {
 PrimaryStatus* primary;
 unsigned char *secondary,*extra,*nested,*global;
 void *connection,*state;
 state=_ZN9GameState11GetInstanceEv();
 connection=Network_GetConnectionManager();
 global=Zone3D_GetMainInstance();
 unsigned char* resources=GameResources_GetInstance();
 primary=GetPrimary(resources);
 secondary=GetSecondary(resources);
 extra=GetExtra(resources);
 void* queue=Network_GetCommandRecordPool();
 StatusPacket packet;
 packet.type=0x97;
 StatusPayload* payload=StatusData(&packet);
 if(Network_IsParentOrOffline(connection)) {
  payload->index=(unsigned char)index;
  payload->a=GameState_GetProgressChapter(state);
  payload->b=GameState_ReadUnknown5cb4(state);
  payload->c=GameState_ReadUnknownCb8(state);
  payload->global=*(unsigned short*)global;
  nested=FieldBattle_GetCombatContext(secondary);
  if(FieldEvent_IsQueuedOrSynchronizing((unsigned char*)primary) && primary->f16 && !primary->inactive) {
   payload->mode=1;
   payload->field8=primary->f16;
   payload->fieldA=primary->f52;
   payload->fieldC=primary->f1a;
   payload->fieldE=primary->f18;
   payload->field6=primary->f1c;
   payload->flag=primary->flags;
  } else {
   unsigned active=secondary[3];
   if((active || (extra[3] && secondary[2])) && nested && !*(signed char*)(nested+0x8e14)) {
    unsigned char* embedded=FieldBattle_GetEncounterRequest(secondary);
    payload->mode=0;
    payload->field8=*(unsigned*)(embedded+12);
    payload->fieldA=*(unsigned short*)(embedded+2);
   } else if(active && *(unsigned*)(*(unsigned char**)(nested+0x8e18)+12)==19) {
    payload->mode=1;
    payload->field8=0x71e8;
    payload->fieldA=0xffff;
    payload->fieldC=0x199;
    payload->fieldE=0x71e8;
    payload->flag=1;
   } else payload->mode=2;
  }
 }
 Network_QueueOutgoingRecord(queue,&packet,0);
}
