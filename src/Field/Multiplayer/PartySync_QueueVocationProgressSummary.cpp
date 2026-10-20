#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_GetObjectWithFlag100(void*,int);
void* Network_GetCommandRecordPool();
unsigned char* GameObject_GetLinkedIndexedState(void*);
void Network_QueueOutgoingRecord(void*,const void*,short);
}
struct Record { unsigned char kind,pad[3]; unsigned short id,value; unsigned char bytes[12]; };
// Original: arm9/ov017 @ 0x021CC97C; symbol: func_ov017_021cc97c; size: 0x84.
extern "C" void PartySync_QueueVocationProgressSummary(int id) {
 void* obj=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),id);
 if(obj) {
  unsigned char* p=GameObject_GetLinkedIndexedState(obj);
  if(p) {
   void* queue=Network_GetCommandRecordPool();
   Record record;
   record.kind=11;
   record.id=id;
   record.value=*(unsigned short*)(p+0x954);
   for(int i=0;i<12;) { int next=i+1; record.bytes[i]=*(p+next+0x186); i=next; }
   Network_QueueOutgoingRecord(queue,&record,0);
  }
 }
}
