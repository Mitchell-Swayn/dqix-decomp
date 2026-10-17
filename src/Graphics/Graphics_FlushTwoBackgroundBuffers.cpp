#include <globaldefs.h>
#include <System/Cache.h>
extern "C" {
extern char data_021052b4[];extern char data_021056b4[];
// Original: arm9/main @ 0x0203BD88; symbol: func_0203bd88; size: 0x28.
void Graphics_FlushTwoBackgroundBuffers(){CleanInvalidateCacheRange(data_021052b4,0x400);CleanInvalidateCacheRange(data_021056b4,0x400);}
}
