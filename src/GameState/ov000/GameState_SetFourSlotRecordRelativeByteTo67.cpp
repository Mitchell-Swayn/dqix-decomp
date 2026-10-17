#include <globaldefs.h>
ARM
extern "C" char *FindFourSlotRecordByIndex(char *, int);
// Original: arm9/ov000 @ 0x0218173C; symbol: func_ov000_0218173c; size: 0x40.
extern "C" void GameState_SetFourSlotRecordRelativeByteTo67(char *base) {
    for (int index = 0; index < 4; ++index) {
        char *record = FindFourSlotRecordByIndex(base, index);
        if (record != 0) {
            int offset = *(signed char *)(record + 0x18);
            *(unsigned char *)(record + offset + 0x10) = 0x67;
        }
    }
}
