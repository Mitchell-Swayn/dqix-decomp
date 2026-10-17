#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_GetObjectWithFlag100(void*,int);
void* ReadGlobalAt02100044();
unsigned char* ReadWordFieldAtOffset150(void*);
void MoveQueuedRecordAndApplySourceValue(void*,const void*,short);
}
struct Record { unsigned char kind,pad[3]; unsigned short id,value; unsigned char bytes[12]; };
// Original: arm9/ov017 @ 0x021CC97C; symbol: func_ov017_021cc97c; size: 0x84.
extern "C" void GameState_QueueObjectTypeElevenRecord(int id) {
 void* obj=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),id);
 if(obj) {
  unsigned char* p=ReadWordFieldAtOffset150(obj);
  if(p) {
   void* queue=ReadGlobalAt02100044();
   Record record;
   record.kind=11;
   record.id=id;
   record.value=*(unsigned short*)(p+0x954);
   for(int i=0;i<12;) { int next=i+1; record.bytes[i]=*(p+next+0x186); i=next; }
   MoveQueuedRecordAndApplySourceValue(queue,&record,0);
  }
 }
}
