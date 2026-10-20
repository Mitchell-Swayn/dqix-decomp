#include <globaldefs.h>
ARM
extern "C" void Memory_AllocateSafe(void);
// Original: arm9/ov016 @ 0x0218F4F0; symbol: func_ov016_0218f4f0; size: 0xC.
extern "C" void ModsNitroStream_AllocateStorage(void)
{
    Memory_AllocateSafe();
}
