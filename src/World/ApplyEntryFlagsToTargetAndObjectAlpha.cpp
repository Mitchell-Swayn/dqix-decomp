#include <globaldefs.h>
#include <World/Object3D.h>
extern "C" void Object_SetUnsignedIntAtOffset5CMask4(void*);extern "C" void WriteWordIndex23Flag8(void*,int);extern "C" void ClampHalfwordFieldToZeroThroughThirtyOne(void*,int);
struct Entry{char pad[12];unsigned flags;};struct Target{char pad[0x50];unsigned flags;};struct State{unsigned flags,value,pad;Entry* entry;unsigned pad2;Target* target;Object3D* object;};
// Original: arm9/main @ 0x02040540; symbol: func_02040540; size: 0x108.
extern "C" ARM void ApplyEntryFlagsToTargetAndObjectAlpha(State* p){if(!p->entry)return;p->flags|=p->entry->flags;if(p->target){if(p->flags&4)Object_SetUnsignedIntAtOffset5CMask4(p->target);if(p->flags&16)WriteWordIndex23Flag8(p->target,1);if(p->flags&32)ClampHalfwordFieldToZeroThroughThirtyOne(p->target,16);if(p->flags&256)p->target->flags|=2;if(p->flags&1024)p->target->flags|=4;if(p->flags&2048)p->target->flags|=8;}else{Object3D* o=p->object;if(o){if(p->flags&4)*(unsigned short*)((char*)o+0xac)|=4;if(p->flags&32)p->object->SetInheritedAlpha(16);}}if(p->flags&8)p->value=0;}
