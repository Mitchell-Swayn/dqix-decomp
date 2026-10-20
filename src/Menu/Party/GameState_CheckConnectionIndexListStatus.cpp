#include <globaldefs.h>
ARM

extern "C" void *Network_GetConnectionManager(void);
extern "C" int Network_IsSessionActive(void *);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *state);

// Original: arm9/ov002 @ 0x02161920; symbol: func_ov002_02161920; size: 0x5C.
extern "C" int GameState_CheckConnectionIndexListStatus(void) {
    if (!Network_IsSessionActive(Network_GetConnectionManager())) goto no_connection;
    unsigned char *list = (unsigned char *)GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    unsigned char index = 0;
    while (index < list[0xf7c]) {
        unsigned char *entry = list + index;
        if (entry[0xf78] == 0) {
            return 2;
        }
        index++;
    }
    return 1;
no_connection:
    return 0;
}
