#include <globaldefs.h>
ARM
extern "C" void Memory_AllocateSafe(void);
// Original: arm9/ov016 @ 0x0218E7A4; symbol: func_ov016_0218e7a4; size: 0xC.
extern "C" void ModsDecoder_AllocateStorage(void)
{
    Memory_AllocateSafe();
}
