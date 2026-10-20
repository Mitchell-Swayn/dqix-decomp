#include <globaldefs.h>
ARM
extern "C" int GameState_ReadLinkedRecordValueByMode(int mode, int index, unsigned char *owner, int *out);
// Original: arm9/ov000 @ 0x02181D68; symbol: GameState_ReadLinkedRecordModeOneIndexOne; size: 0x20.
// Reads a linked-record value using mode 1 and index 1.
extern "C" int GameState_ReadLinkedRecordModeOneIndexOne(void *unused, unsigned char *owner, int *out) {
    return GameState_ReadLinkedRecordValueByMode(1, 1, owner, out);
}
