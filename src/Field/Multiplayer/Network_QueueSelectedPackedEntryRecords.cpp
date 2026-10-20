#include <globaldefs.h>
ARM
struct Packed {unsigned short a:2,b:4,c:3,d:3,e:2,rest:2;};
struct Entry {char pad[4];unsigned short x,y,z,w;char gap[22];Packed flags;unsigned char v0,v1;char tail[126];};
struct Payload {unsigned short id,index;Packed flags;unsigned char v0,v1;unsigned short x,y,z,w;};
struct Message {unsigned char command;char pad[3];Payload payload;};
struct Count {unsigned char count:4,rest:4;};
struct Groups {unsigned char pad;unsigned char first:4,count:2,rest:2;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameResources_GetInstance();
extern "C" char* FieldBattle_GetEncounterRequest(void*);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
// Original: arm9/ov017 @ 0x021CA534; symbol: func_ov017_021ca534; size: 0x1A8.
extern "C" void Network_QueueSelectedPackedEntryRecords(char* self) {
 _ZN9GameState11GetInstanceEv();
 char* state=FieldBattle_GetEncounterRequest(*(void**)(GameResources_GetInstance()+0x3718));
 void* connection=Network_GetCommandRecordPool();
 for(int i=0;i<((Groups*)self)->count;i++) {
 char* group=self+4+i*24;
 Message message;
 for(int j=0;j<((Count*)(group+10))->count;j++) {
 if(*(unsigned char*)(group+2+j)<8) {
 Entry* entry=(Entry*)(state+0x158+*(unsigned char*)(group+2+j)*0xa4);
 Payload* payload=&message.payload;
 message.command=0x5d;
 payload->id=*(unsigned short*)(state+8);
 payload->index=*(unsigned char*)(group+2+j)+0xc0;
 payload->flags.a=(unsigned char)entry->flags.a;
 payload->flags.b=(unsigned char)entry->flags.b;
 payload->flags.c=(unsigned char)entry->flags.c;
 payload->flags.d=(unsigned char)entry->flags.d;
 payload->flags.e=(unsigned char)entry->flags.e;
 payload->v0=entry->v0;
 payload->v1=entry->v1;
 payload->x=entry->x;
 payload->y=entry->y;
 payload->z=entry->z;
 payload->w=entry->w;
 Network_QueueOutgoingRecord(connection,&message,0);
 }
 }
 }
}
