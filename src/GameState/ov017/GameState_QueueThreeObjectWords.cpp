#include <globaldefs.h>
ARM
struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" void* ReadGlobalAt02100044();
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
extern "C" void MoveQueuedRecordAndApplySourceValue(Object*,const void*,short);
struct Record {unsigned char type; int words[3]; short id; unsigned char index;};
// Original: arm9/ov017 @ 0x021CCB58; symbol: func_ov017_021ccb58; size: 0x84.
extern "C" void GameState_QueueThreeObjectWords(int id,int index){
 void* o=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),id);
 if(o){unsigned char* p=ReadWordFieldAtOffset150(o); if(p){
 Object* queue=(Object*)ReadGlobalAt02100044();
 Record r;r.type=13;r.id=id;r.index=index;
 for(unsigned char i=0;i<3;i++)r.words[i]=*(int*)(p+0x138+(i+index)*4);
 MoveQueuedRecordAndApplySourceValue(queue,&r,0);
 }}
}
