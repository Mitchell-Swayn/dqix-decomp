#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" void* Network_GetCommandRecordPool();
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
struct Packed { unsigned x:10,y:10,z:10,pad:2; };
struct Triple { Packed a,b,c; };
struct Payload { Packed a,b,c; unsigned index:8,party:3,flag:1,pad:20; };
struct Event { unsigned char type; Payload payload; };
// Original: arm9/ov017 @ 0x021CF078; symbol: func_ov017_021cf078; size: 0x1BC.
extern "C" void CharacterState_QueueVocationStatBonuses(int party,int index,int flag) {
 void* owner=Network_GetCommandRecordPool();
 void* obj=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),party);
 if(obj) {
 unsigned char* data=GameObject_GetLinkedIndexedState(obj);
 if(data) {
 Event event;
 event.type=0x15;
 Triple* src=(Triple*)(data+0x850)+index;
 Payload* dst=&event.payload;
 dst->a.x=src->a.x;dst->a.y=src->a.y;dst->a.z=src->a.z;
 dst->b.x=src->b.x;dst->b.y=src->b.y;dst->b.z=src->b.z;
 dst->c.x=src->c.x;dst->c.y=src->c.y;dst->c.z=src->c.z;
 dst->index=index;dst->party=party;dst->flag=flag;
 Network_QueueOutgoingRecord(owner,&event,0);
 }
 }
}
