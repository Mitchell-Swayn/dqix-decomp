#include <globaldefs.h>
ARM
extern "C" int GameState_ReadLinkedRecordValueByMode(int mode, int index, unsigned char *owner, int *out);
// Original: arm9/ov000 @ 0x02181E30; symbol: GameState_ReadLinkedRecordModeZeroIndexZero; size: 0x20.
// Reads a linked-record value using mode 0 and index 0.
extern "C" int GameState_ReadLinkedRecordModeZeroIndexZero(void *unused, unsigned char *owner, int *out) {
    return GameState_ReadLinkedRecordValueByMode(0, 0, owner, out);
}
