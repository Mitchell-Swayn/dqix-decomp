#include <globaldefs.h>
ARM
extern "C" void OnlineMemory_AllocateTagged(void *, void *, unsigned);
// Original: arm9/ov031 @ 0x02211B54; symbol: func_ov031_02211b54; size: 0x10.
extern "C" void OnlineMemory_AllocateAligned(void *a, void *b) {
    OnlineMemory_AllocateTagged(a, b, 0x20);
}
