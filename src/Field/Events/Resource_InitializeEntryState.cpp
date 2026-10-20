#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *);
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov017 @ 0x021AA16C; symbol: func_ov017_021aa16c; size: 0x40.
extern "C" void Resource_InitializeEntryState(signed char *entry) {
    GameResources_GetInstance();
    LinkedQueue_InitializeNodeStatus(entry);
    entry[0] = 0x3C;
    memset(entry + 8, -1, 8);
    entry[0x10] = 0;
    entry[0x11] = 0;
    *(short *)(entry + 0x12) = 0;
}
