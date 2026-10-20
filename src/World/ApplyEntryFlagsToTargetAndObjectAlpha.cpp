#include <globaldefs.h>
#include <World/Object3D.h>
extern "C" void ActorSprite_DisableAutomaticMovementFacing(void*);extern "C" void ActorSprite_SetMovingAnimationOverride(void*,int);extern "C" void ActorSprite_SetAlpha(void*,int);
struct Entry{char pad[12];unsigned flags;};struct Target{char pad[0x50];unsigned flags;};struct State{unsigned flags,value,pad;Entry* entry;unsigned pad2;Target* target;Object3D* object;};
// Original: arm9/main @ 0x02040540; symbol: func_02040540; size: 0x108.
extern "C" ARM void ApplyEntryFlagsToTargetAndObjectAlpha(State* p){if(!p->entry)return;p->flags|=p->entry->flags;if(p->target){if(p->flags&4)ActorSprite_DisableAutomaticMovementFacing(p->target);if(p->flags&16)ActorSprite_SetMovingAnimationOverride(p->target,1);if(p->flags&32)ActorSprite_SetAlpha(p->target,16);if(p->flags&256)p->target->flags|=2;if(p->flags&1024)p->target->flags|=4;if(p->flags&2048)p->target->flags|=8;}else{Object3D* o=p->object;if(o){if(p->flags&4)*(unsigned short*)((char*)o+0xac)|=4;if(p->flags&32)p->object->SetInheritedAlpha(16);}}if(p->flags&8)p->value=0;}
