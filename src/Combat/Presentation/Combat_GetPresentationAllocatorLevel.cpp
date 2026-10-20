#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021E8BA4; symbol: Resource_ReadByteAtOffset30; size: 0x8.
// Returns the unsigned byte at offset 0x30 from the resource list context used by the combat object loader.
extern "C" unsigned int Combat_GetPresentationAllocatorLevel(void *self) { return *((unsigned char *)self + 0x30); }
