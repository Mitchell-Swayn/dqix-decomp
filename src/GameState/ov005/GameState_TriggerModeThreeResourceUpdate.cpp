#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" unsigned int OV017_ReadWordField1C(void *);
extern "C" void Resource_ConfigureTwoFixedPointRecords(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov005 @ 0x0215A37C; symbol: func_ov005_0215a37c; size: 0x40.
extern "C" void GameState_TriggerModeThreeResourceUpdate(unsigned char *state) {
    if (*(unsigned char *)(state + 0x3000 + 0xdb8) != 3) return;
    unsigned char *resources = (unsigned char *)GameResources_GetInstance();
    unsigned int value = OV017_ReadWordField1C(*(void **)(resources + 0x3000 + 0x708));
    Resource_ConfigureTwoFixedPointRecords(value, 0xbd, 0x10, 0xbd, 0x2f);
}
