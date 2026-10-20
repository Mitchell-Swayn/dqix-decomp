#include <globaldefs.h>
ARM
struct Object;struct GameResources;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
struct PackedFlags {unsigned char a:1,b:1,c:1,d:1,kind:4;};
struct ByteFlags {unsigned char a:1,b:1,c:1,d:1,e:1,f:1,g:1,h:1;};
struct BoolFlags {bool a:1,b:1,c:1,d:1,e:1,f:1,g:1,h:1;};
struct Source {unsigned char pad[12];unsigned short fieldC;unsigned char padE[0x30-14];unsigned short field30;short field32,field34;unsigned short pad36;unsigned char field38,pad39[2];PackedFlags packed;ByteFlags flags;unsigned char field3D;};
struct Payload {unsigned short owner,index;short a,b;unsigned short c,d;unsigned char e;PackedFlags packed;unsigned char f;BoolFlags flags;};
struct Record {unsigned char type;char pad[3];Payload payload;};
struct GroupCount {unsigned char count:4,rest:4;};
struct ParentCount {unsigned char low:4,count:2,high:2;};
static inline unsigned ReadPacked_a(Source *s){return s->packed.a;}
static inline unsigned ReadPacked_b(Source *s){return s->packed.b;}
static inline unsigned ReadPacked_c(Source *s){return s->packed.c;}
static inline unsigned ReadPacked_d(Source *s){return s->packed.d;}
static inline unsigned ReadPacked_kind(Source *s){return s->packed.kind;}
// Original: arm9/ov017 @ 0x021CA9BC; symbol: func_ov017_021ca9bc; size: 0x2C0.
// Queues type5F records for grouped combatant slots, preserving individual packed flags.
extern "C" void QueueGroupedCombatantStatusRecords(unsigned char *input){
 _ZN9GameState11GetInstanceEv();unsigned char *resources=(unsigned char*)GameResources_GetInstance();unsigned char *state=(unsigned char*)FieldBattle_GetEncounterRequest(*(void**)(resources+0x3718));Object *queue=(Object*)Network_GetCommandRecordPool();
 for(int group=0;group<((ParentCount*)(input+1))->count;group++){
 unsigned char *entry=input+4+24*group;
 for(int i=0;i<((GroupCount*)(entry+10))->count;i++){
 unsigned char *ids=entry+2;if(ids[i]>=8)continue;
 Source *s=(Source*)(state+0x158+0xa4*ids[i]);Record r;Payload *p=&r.payload;
 r.type=0x5f;p->owner=*(unsigned short*)(state+8);p->index=ids[i]+0xc0;p->a=s->field32;p->b=s->field34;p->c=s->fieldC;p->d=s->field30;p->e=s->field38;
 p->packed.a=(unsigned char)ReadPacked_a(s);p->packed.b=(unsigned char)ReadPacked_b(s);p->packed.c=(unsigned char)ReadPacked_c(s);p->packed.d=(unsigned char)ReadPacked_d(s);p->packed.kind=(unsigned char)ReadPacked_kind(s);
 p->flags.a=s->flags.a!=0;p->flags.b=s->flags.b!=0;p->flags.c=s->flags.c!=0;p->flags.d=s->flags.d!=0;p->flags.e=s->flags.e!=0;p->flags.f=s->flags.f!=0;p->flags.g=s->flags.g!=0;p->f=s->field3D;
 Network_QueueOutgoingRecord(queue,&r,0);
 }}
}
