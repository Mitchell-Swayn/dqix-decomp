#include <globaldefs.h>
ARM
struct Payload {unsigned char id,kind;unsigned short source;short value;short pad;float timer;unsigned short meta,extra;};
struct Message {unsigned char command;char pad[3];Payload payload;};
struct Map {unsigned short key;unsigned short pad:4,value:12;unsigned short extra;};
struct Cache {unsigned short key,value;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned* Network_GetConnectionManager();
extern "C" unsigned short* Zone3D_GetMainInstance();
extern "C" char* GameResources_GetInstance();
extern "C" void* ZoneState_GetTrackedZoneCache();
extern "C" void* Network_GetCommandRecordPool();
extern "C" void* memset(void*,int,unsigned);
extern "C" char* FieldBattle_GetCombatContext(void*);
extern "C" char* FieldBattle_GetEncounterRequest(void*);
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" int FieldEvent_IsQueuedOrSynchronizing(void*);
extern "C" unsigned PartySelection_GetMemberMask(void*,unsigned);
extern "C" int FieldBattle_IsSceneInSupportedSyncPhase(void*);
extern "C" float _ZNK9GameState11GetDayTimerEv(void*);
extern "C" Map* ZoneState_FindTrackedZoneByIdentifier(void*,int);
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
// Original: arm9/ov017 @ 0x021C4FA0; symbol: func_ov017_021c4fa0; size: 0x220.
extern "C" void Network_QueueSelectedSourceAndDayTimer(int id,int key) {
 void* game=_ZN9GameState11GetInstanceEv();
 unsigned* connection=Network_GetConnectionManager();
 unsigned short* global=Zone3D_GetMainInstance();
 char* resources=GameResources_GetInstance();
 Payload* out;char* data;
 char* primary=*(char**)(resources+0x3734);
 ZoneState_GetTrackedZoneCache();
 void* queue=Network_GetCommandRecordPool();
 Message message;message.command=0x8f;
 out=&message.payload;
 memset(out,0,16);
 out->kind=0;out->id=id;out->timer=-1.0f;
 char* owner;
 char* control=*(char**)(resources+0x3718);
 owner=FieldBattle_GetCombatContext(control);
 data=FieldBattle_GetEncounterRequest(control);
 if(Network_IsParentOrOffline(connection)) {
 int selected=1;
 if(*(unsigned short*)(primary+0x1a)!=key||(*(unsigned short*)(primary+0x50)&0x800)) {
 if(*(unsigned short*)(primary+0x1c)!=key)selected=0;
 }
 if(FieldEvent_IsQueuedOrSynchronizing(primary)&&*(unsigned char*)(primary+0x12)&&!*(unsigned char*)(primary+0x106)&&selected) {
 out->kind=1;
 unsigned short source=*(unsigned short*)(primary+0x18);
 if(source==0) {
 out->source=*(unsigned short*)(primary+8);
 out->value=*(short*)(primary+0x52);
 } else {
 out->source=source;
 out->value=*(short*)(primary+0x52);
 }
 } else if(*(unsigned char*)(control+2)&&(!owner||!*(signed char*)(owner+0x8e14))&&data&&!PartySelection_GetMemberMask(data,(unsigned char)id)&&!FieldBattle_IsSceneInSupportedSyncPhase(control)&&*(int*)(data+12)>=0) {
 out->kind=2;
 out->source=*(int*)(data+12);
 out->value=global[0];
 }
 out->timer=_ZNK9GameState11GetDayTimerEv(game);
 Map* found=ZoneState_FindTrackedZoneByIdentifier(ZoneState_GetTrackedZoneCache(),key);
 if(found) {
 out->meta=found->value;out->extra=found->extra;
 } else {
 Cache* cache=(Cache*)(resources+0x44b4);
 if(cache->key==key)out->meta=cache->value;else out->meta=0;
 out->extra=0;
 }
 }
 Network_QueueOutgoingRecord(queue,&message,0);
}
