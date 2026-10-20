#include <globaldefs.h>
#include <System/Cache.h>
ARM
extern "C" int MBi_SendMP(void*,unsigned,unsigned);
// Original: arm9/ov027 @ 0x021DAB00; symbol: func_ov027_021dab00; size: 0x38.
// Flushes the aligned packet range and drains writes before sending the completed block.
extern "C" int MBi_BlockHeaderEnd(unsigned length,unsigned destinations,void *buffer)
{
    CleanInvalidateCacheRange(buffer,(length+31)&~31);
    DrainWriteBuffer();
    return MBi_SendMP(buffer,length,destinations);
}
