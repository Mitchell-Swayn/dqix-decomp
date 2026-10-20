#include <globaldefs.h>
ARM
struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" void* Network_GetCommandRecordPool();
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
struct Record {unsigned char type; int words[3]; short id; unsigned char index;};
// Original: arm9/ov017 @ 0x021CCB58; symbol: func_ov017_021ccb58; size: 0x84.
extern "C" void GameState_QueueThreeObjectWords(int id,int index){
 void* o=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),id);
 if(o){unsigned char* p=GameObject_GetLinkedIndexedState(o); if(p){
 Object* queue=(Object*)Network_GetCommandRecordPool();
 Record r;r.type=13;r.id=id;r.index=index;
 for(unsigned char i=0;i<3;i++)r.words[i]=*(int*)(p+0x138+(i+index)*4);
 Network_QueueOutgoingRecord(queue,&r,0);
 }}
}
