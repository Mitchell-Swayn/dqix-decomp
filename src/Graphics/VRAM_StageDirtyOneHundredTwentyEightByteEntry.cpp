#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
struct Flags{unsigned char dirty:1;unsigned char rest:7;};struct Object{const void* data;unsigned offset;int id;char pad[10];Flags flags;};
// Original: arm9/main @ 0x02041754; symbol: func_02041754; size: 0x5C.
extern "C" ARM void VRAM_StageDirtyOneHundredTwentyEightByteEntry(Object* p){if(p->id>=0 && p->flags.dirty && p->data){StageMemoryToVRAM((VRAMSubregion)1,p->data,p->offset,128,true,true);p->flags.dirty=0;}}
