#include <globaldefs.h>
ARM
extern "C" void *Network_GetConnectionManager();
extern "C" int Network_IsClientSession(unsigned int *);
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *GameState_GetIndexList(void *);
extern "C" void *Zone3D_GetMainInstance();
extern "C" void QueueTag27ForPositiveIdWhenStateInactive(int, unsigned short);
// Original: arm9/ov017 @ 0x021CE4E0; symbol: GameState_QueueActiveIndexWithGlobalValue; size: 0x44.
// When the connection state is inactive and GameState's index-list byte +0xf7d is nonzero, queues that byte with the global halfword value through QueueTag27ForPositiveIdWhenStateInactive.
extern "C" void GameState_QueueActiveIndexWithGlobalValue(void) {
    if (Network_IsClientSession((unsigned int *)Network_GetConnectionManager())) return;
    void *list = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    if (*((unsigned char *)list + 0xf7d) == 0) return;
    void *global = Zone3D_GetMainInstance();
    unsigned char index = *((unsigned char *)list + 0xf7d);
    QueueTag27ForPositiveIdWhenStateInactive(index, *(unsigned short *)global);
}
