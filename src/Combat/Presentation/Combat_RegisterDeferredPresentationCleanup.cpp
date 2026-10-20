#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021E8BAC; symbol: func_ov025_021e8bac; size: 0x18.
extern "C" void Combat_RegisterDeferredPresentationCleanup(unsigned char* owner, unsigned char* node) { node[1] = owner[0x30]; *(unsigned int*)(node + 8) = *(unsigned int*)(owner + 0x1d8); *(unsigned int*)(owner + 0x1d8) = (unsigned int)node; }
