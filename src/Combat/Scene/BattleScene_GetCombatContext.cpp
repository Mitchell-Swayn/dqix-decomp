#include <globaldefs.h>
// Original: arm9/ov000 @ 0x02160EF8; symbol: Combat_GetWordAtOffset29C; size: 0x8.
// Returns the 32-bit value stored at object byte offset 0x29c; its caller uses the accessor in combat selection handling.
ARM
extern "C" unsigned int BattleScene_GetCombatContext(void *object) {
    return *(unsigned int *)((unsigned char *)object + 0x29c);
}
