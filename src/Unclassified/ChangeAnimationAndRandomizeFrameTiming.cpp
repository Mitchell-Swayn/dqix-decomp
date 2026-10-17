#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" int Object_FindTextInThirtyByteEntries(void*);extern "C" unsigned data_02114e50;
struct Frame{unsigned pad,duration,other;};struct Animation{unsigned pad;Frame* frames;};struct Flag {unsigned char enabled:1,rest:7;};struct Object{char pad[12];Animation* animations;char pad2[4];char node[0x5c];unsigned frame;int animation;unsigned remaining,duration;char pad3[4];Flag flags;};
// Original: arm9/main @ 0x0204792C; symbol: func_0204792c; size: 0x8C.
extern "C" ARM void ChangeAnimationAndRandomizeFrameTiming(Object* p){if(!p->flags.enabled)return;int id=Object_FindTextInThirtyByteEntries(p->node);if(p->animation==id||!id)return;p->animation=id;p->frame=0;p->remaining=data_02114e50;p->duration=p->animations[p->animation].frames[p->frame].duration;p->remaining-=((unsigned)rand())%p->duration;}
