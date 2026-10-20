#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02163B60; symbol: Object_ClearFieldsAt6E2EAnd6E30; size: 0x30.
// Clears the byte at base+0x6e2e and three halfwords beginning at base+0x6e30; semantic field roles remain unknown.
extern "C" void CombatScene_ClearFadingEnemyList(void *base) {
    *(unsigned char *)((unsigned char *)base + 0x6e2e) = 0;
    for (int i = 0; i < 3; i++)
        *(unsigned short *)((unsigned char *)base + 0x6e30 + i * 2) = 0;
}
