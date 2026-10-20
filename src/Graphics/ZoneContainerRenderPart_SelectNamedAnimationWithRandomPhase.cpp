#include <globaldefs.h>
#include <std_library_functions.h>
// Original data: arm9/main @ 0x2114e50; symbol: data_02114e50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int Resource_FindAnimationNameIndex(void*);extern "C" unsigned FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;
struct Frame{unsigned pad,duration,other;};struct Animation{unsigned pad;Frame* frames;};struct Flag {unsigned char enabled:1,rest:7;};struct Object{char pad[12];Animation* animations;char pad2[4];char node[0x5c];unsigned frame;int animation;unsigned remaining,duration;char pad3[4];Flag flags;};
// Original: arm9/main @ 0x0204792C; symbol: func_0204792c; size: 0x8C.
extern "C" ARM void ZoneContainerRenderPart_SelectNamedAnimationWithRandomPhase(Object* p){if(!p->flags.enabled)return;int id=Resource_FindAnimationNameIndex(p->node);if(p->animation==id||!id)return;p->animation=id;p->frame=0;p->remaining=FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;p->duration=p->animations[p->animation].frames[p->frame].duration;p->remaining-=((unsigned)rand())%p->duration;}
