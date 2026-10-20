#include <globaldefs.h>
ARM
#pragma opt_propagation off
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned short* Zone3D_GetMainInstance();extern "C" float _ZNK9GameState11GetDayTimerEv(void*);struct Message{unsigned short a,b,c;short d;char e;unsigned short f;char value;float time;};extern "C" void Field_QueuePairedStateRequest(Message*);
// Original: arm9/ov017 @ 0x021BC6E0; symbol: QueueObjectHalfwordsAndDayTimerRecord; size: 0x9c.
extern "C" void FieldEvent_QueueZoneEventAndDayTimer(char* self,int value,unsigned flags){
void* state=_ZN9GameState11GetInstanceEv();unsigned short* global=Zone3D_GetMainInstance();Message msg;int zero=0;msg.value=zero-1;msg.a=zero;msg.b=zero;msg.c=zero;msg.d=zero;msg.e=zero;msg.f=zero;msg.time=0.f;if(!(flags&0x800))msg.a=*global;msg.b=*(unsigned short*)(self+0x16);msg.c=*(unsigned short*)(self+0x18);msg.e=0;msg.f=*(unsigned short*)(self+0x1c);msg.d=*(short*)(self+0x52);msg.time=_ZNK9GameState11GetDayTimerEv(state);msg.value=value;Field_QueuePairedStateRequest(&msg);
}
