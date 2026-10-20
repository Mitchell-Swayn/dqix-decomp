#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern char Main_UnknownRoleZeroInitializedStorage[];void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);}
struct Object {unsigned char pad[0x3daa];unsigned char reset;char pad2[0x11];unsigned char index;signed char phase;unsigned char previous;signed char previousPhase;char pad3[12];unsigned flags;char pad4[0x2c];unsigned char phases[256];};
// Original: arm9/ov005 @ 0x02158560; symbol: func_ov005_02158560; size: 0x9C.
extern "C" int SwitchIndexedStateAndSavePreviousPhase(Object* p,int index,int silent){
if(index==p->index)return 0;
if(!silent)SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
p->previous=p->index;
p->previousPhase=p->phase;
*(signed char*)&p->phases[p->index]=p->phase;
(*(signed char*)&p->index)=index;
p->phase=p->phases[(unsigned char)index];
p->flags|=0x840;
p->reset=0;
return 1;
}
