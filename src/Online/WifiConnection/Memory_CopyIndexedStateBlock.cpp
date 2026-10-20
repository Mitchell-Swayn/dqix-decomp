#include <globaldefs.h>
ARM
extern "C" int Network_GetConnectionWorkspace(unsigned int);
extern "C" void MIi_CpuCopy32(const void *, void *, unsigned int);
// Original: arm9/ov031 @ 0x02213204; symbol: Memory_CopyIndexedStateBlock; size: 0x2C.
// Selects the state base with mask 0x10 and copies 0xf0 bytes from base plus index*0x100 to the output.
extern "C" void Memory_CopyIndexedStateBlock(unsigned int index, void *destination) {
    unsigned int word;
    register void *savedDestination = destination;
    word = Network_GetConnectionWorkspace(0x10);
    MIi_CpuCopy32(savedDestination, (void *)(word + (index << 8)), 0xf0);
}
