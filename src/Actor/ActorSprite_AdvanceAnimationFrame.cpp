#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e50; symbol: data_02114e50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;
struct Resource {char pad[8];unsigned* next;unsigned* durations;};
extern "C" char* Resource_GetActiveGraphicCacheEntry(void*,int);
extern "C" Resource* ActorSpriteResource_GetAnimation(void*,unsigned);
struct State {void* owner;char pad4[36];short active;char pad2a[6];unsigned a,index,last,duration;float rate;unsigned previousA,previousIndex;};
// Original: arm9/main @ 0x0203F20C; symbol: func_0203f20c; size: 0xA4.
extern "C" void ActorSprite_AdvanceAnimationFrame(State* p) {
    if(p->active<0)return;char* owner=Resource_GetActiveGraphicCacheEntry(p->owner,p->active);if(!owner)return;
    Resource* data=ActorSpriteResource_GetAnimation(owner+16,p->a);if(!data)return;
    if(FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2-p->last<=p->duration)return;
    p->previousA=p->a;p->previousIndex=p->index;p->index=data->next[p->index];p->last=FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;
    p->duration=(unsigned)((float)data->durations[p->index]/p->rate);
}
