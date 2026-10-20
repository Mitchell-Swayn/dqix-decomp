#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned int);
// Original: arm9/ov000 @ 0x021637C8; symbol: func_ov000_021637c8; size: 0x34.
extern "C" void CombatScene_ResetPartyAnimationQueue(unsigned char *base) {
    memset(base + 0x773c, -1, 4);
    memset(base + 0x7740, 0, 4);
}
