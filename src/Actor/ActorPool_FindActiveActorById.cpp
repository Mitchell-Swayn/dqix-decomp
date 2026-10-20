#include <globaldefs.h>
extern "C" unsigned short* Actor_GetPlacementDescriptor(void*);
struct Entry { unsigned flags; }; struct Table { char pad[12]; Entry* entries[32]; };
// Original: arm9/main @ 0x0203DF78; symbol: func_0203df78; size: 0x64.
extern "C" ARM Entry* ActorPool_FindActiveActorById(Table* t,unsigned id) { for(int i=0;i<32;i++){ Entry* e=t->entries[i]; if(e && !(e->flags&0x8000)){ unsigned short* k=Actor_GetPlacementDescriptor(e); if(k && *k==id) return t->entries[i]; }} return 0; }
