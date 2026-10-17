#include <globaldefs.h>
ARM
extern "C" unsigned data_02114e50;
struct Resource {char pad[8];unsigned* next;unsigned* durations;};
extern "C" char* Object_GetValidSixtyByteEntry(void*,int);
extern "C" Resource* GetTwentyByteEntryByBoundedIndex(void*,unsigned);
struct State {void* owner;char pad4[36];short active;char pad2a[6];unsigned a,index,last,duration;float rate;unsigned previousA,previousIndex;};
// Original: arm9/main @ 0x0203F20C; symbol: func_0203f20c; size: 0xA4.
extern "C" void AdvanceTimedAnimationFrame(State* p) {
    if(p->active<0)return;char* owner=Object_GetValidSixtyByteEntry(p->owner,p->active);if(!owner)return;
    Resource* data=GetTwentyByteEntryByBoundedIndex(owner+16,p->a);if(!data)return;
    if(data_02114e50-p->last<=p->duration)return;
    p->previousA=p->a;p->previousIndex=p->index;p->index=data->next[p->index];p->last=data_02114e50;
    p->duration=(unsigned)((float)data->durations[p->index]/p->rate);
}
