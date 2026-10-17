#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void ClearThree32ByteBlocks(void*);
// Original: arm9/main @ 0x0203B66C; symbol: func_0203b66c; size: 0xC.
extern "C" void ClearThreeThirtyTwoByteMemoryRegions(void* object){ClearThree32ByteBlocks(object);}
