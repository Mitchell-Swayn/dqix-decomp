#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *state);
// Original: arm9/ov003 @ 0x02160BF8; symbol: func_ov003_02160bf8; size: 0x60.
extern "C" void *GameState_FindRecordBySignedSixBitId(unsigned unused, int id) {
    if (id < 0) return 0;
    char *list = (char *)GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    char *records = list + 0xF80;
    unsigned char index = 0;
    while (index < *((unsigned char *)(list + 0x2C8C))) {
        char *record = records + index * 0x23C;
        int entry = (*(signed char *)record << 26) >> 26;
        if (id == entry) return record;
        index = (unsigned char)(index + 1);
    }
    return 0;
}
