#include <globaldefs.h>
ARM
extern "C" { void* _ZN9GameState11GetInstanceEv(); void* GameState_GetObjectWithFlag100(void*,int); void* Network_GetCommandRecordPool(); unsigned char* GameObject_GetLinkedIndexedState(void*); void Network_QueueOutgoingRecord(void*,const void*,short); }
struct Record { unsigned char type,pad[3]; unsigned short values[6]; unsigned short id; unsigned char start; };
// Original: arm9/ov017 @ 0x021CCA5C; symbol: func_ov017_021cca5c; size: 0x9C.
extern "C" void GameState_QueueSixHalfwordObjectRange(int id,int range) {
 void* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),id);
 if(object) {
  unsigned char* source=GameObject_GetLinkedIndexedState(object);
  if(source) {
   void* queue=Network_GetCommandRecordPool();
   Record record;
   record.type=12;
   record.id=id;
   unsigned char start;
   if(range==0) { record.start=1; start=1; }
   else { record.start=7; start=7; }
   for(unsigned char i=0;i<6;++i) record.values[i]=*(unsigned short*)(source+(i+start)*2+0x16c);
   Network_QueueOutgoingRecord(queue,&record,0);
  }
 }
}
