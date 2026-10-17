#include "globaldefs.h"
#pragma optimize_for_size off
ARM
struct Flags{unsigned char a:1;unsigned char active:1;unsigned char other:6;};struct Entry{unsigned char pad[0xb2];short state;unsigned char pad2[0x18];Flags flags;unsigned char pad3[7];};struct Object{unsigned char pad[8];Entry entries[16];};extern "C" void Object3D_DrawEntryWithOptionalInverseViewTransform(Entry*,int);
// Original: arm9/main @ 0x02057A10; symbol: func_02057a10; size: 0x5C.
extern "C" void InitializeInactiveEntriesWithObjectIndices208Through223(Object*p){for(int i=0;i<16;i++){if(!p->entries[i].flags.active && p->entries[i].state<=-1)Object3D_DrawEntryWithOptionalInverseViewTransform(p->entries+i,i+208);}}
