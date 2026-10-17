#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/ov008 @ 0x0218B1E0; symbol: func_ov008_0218b1e0; size: 0x60.
extern "C" void GameState_SetFirstUnusedRecordFromParameter(unsigned char *parameter) {
    unsigned char *countField = (unsigned char *)_ZN9GameState11GetInstanceEv() + 0x71FC;
    unsigned char *entry = countField + 4;
    for (int i = 0; i < 16; entry += 0x2C, ++i) {
        if ((((unsigned int)*(unsigned short *)(entry + 0x12) << 17) >> 31) == 0) {
            memcpy(entry, parameter + 0xDF0, 0x2C);
            *countField = (unsigned char)(*countField + 1);
            return;
        }
    }
}
