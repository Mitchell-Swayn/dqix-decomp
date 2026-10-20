#include <globaldefs.h>
ARM
extern "C" int Resource_RebuildPriorityStateByMode(unsigned);
extern "C" unsigned char FindPriorityBitByRank(unsigned);
extern "C" int Network_StartSecondAccessPointSearchPass(void*);
// Original: arm9/ov031 @ 0x02215150; symbol: func_ov031_02215150; size: 0x60.
extern "C" int Network_SelectFallbackSsidScanPhase(unsigned char* self) {
    if (*(unsigned short*)(self + 0xd16) != 0 && Resource_RebuildPriorityStateByMode(2) != 0) {
        self[0xd11] = (unsigned char)FindPriorityBitByRank(0);
        return 5;
    }
    unsigned nibble = ((unsigned)self[0xd0b] << 24) >> 28;
    if (nibble >= 1) return 6;
    return Network_StartSecondAccessPointSearchPass(self);
}
