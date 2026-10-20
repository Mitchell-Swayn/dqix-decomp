#include <globaldefs.h>
ARM
extern "C" unsigned TextContext_GetSharedInstance(void);
// Original: arm9/ov004 @ 0x02165B14; symbol: SetGlobalObjectByte19B2AndWord99C; size: 0x24.
// Obtains the current object and writes byte 1 at offset 0x19B2 and word 2 at offset 0x99C.
extern "C" unsigned TreasureMapMenu_ConfigureSecondaryMessageAdvance(void) {
    char *object = (char *)TextContext_GetSharedInstance();
    *(unsigned char *)(object + 0x19b2) = 1;
    *(unsigned *)(object + 0x99c) = 2;
    return 0;
}
