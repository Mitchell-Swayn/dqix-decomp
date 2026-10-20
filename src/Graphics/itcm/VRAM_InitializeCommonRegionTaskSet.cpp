#include <globaldefs.h>
ARM
extern "C" void _ZN18VRAMStagingManager23CommonVRAMRegionTaskSet5ResetEv(void*);
// Original: arm9/itcm @ 0x01FF96FC; symbol: func_01ff96fc; size: 0x1C.
extern "C" void* VRAM_InitializeCommonRegionTaskSet(void* self, unsigned int value, unsigned short size) { *(unsigned int*)self = value; *(unsigned short*)((char*)self + 4) = size; _ZN18VRAMStagingManager23CommonVRAMRegionTaskSet5ResetEv(self); return self; }
