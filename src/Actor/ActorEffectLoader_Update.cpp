#include <globaldefs.h>
struct Object {char pad[13];unsigned char flags;};
extern "C" void PollAndConsumeFourBackgroundTasks(Object*);
extern "C" void Graphics_UpdateIndexedObjectEffects(Object*);
// Original: arm9/main @ 0x020DA2FC; symbol: func_020da2fc; size: 0x20.
extern "C" void ActorEffectLoader_Update(Object* p) {if(p->flags&1)PollAndConsumeFourBackgroundTasks(p);else Graphics_UpdateIndexedObjectEffects(p);}
