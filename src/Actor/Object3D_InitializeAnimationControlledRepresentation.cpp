#include <globaldefs.h>
struct Object {unsigned short flags;char pad2[0x12e];unsigned counter;};
extern "C" void Object_InitializeAnimationControlDefaults(Object*);
// Original: arm9/main @ 0x02048120; symbol: func_02048120; size: 0x24.
extern "C" void Object3D_InitializeAnimationControlledRepresentation(Object* p) {Object_InitializeAnimationControlDefaults(p);p->flags|=0x40;p->counter=0;}
