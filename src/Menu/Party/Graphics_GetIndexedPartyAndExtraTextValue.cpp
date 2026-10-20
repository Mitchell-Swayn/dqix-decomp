#include <globaldefs.h>
ARM
extern "C" void GameState_BuildOutputWordListFromIndexedData(void *, unsigned int *);
// Original: arm9/ov002 @ 0x021573F8; symbol: Graphics_GetIndexedPartyAndExtraTextValue; size: 0x2C.
// Returns -1 for a negative index; otherwise builds the seven-word party/extra-text result and returns the indexed word.
extern "C" int Graphics_GetIndexedPartyAndExtraTextValue(void *source, int index) {
    unsigned int values[7];
    if (index < 0) return -1;
    GameState_BuildOutputWordListFromIndexedData(source, values);
    return values[index];
}
