#include <globaldefs.h>
ARM
extern "C" void *Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void *);
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadFirstObjectIndex(void *);
extern "C" void Network_QueuePartyControlLock(int, int, int);
extern "C" int Filesystem_QueuePendingLoadsInBatchesOfFive(void *);
extern "C" void Event_InstantiateLoadedSceneObjects(void *);
extern "C" void Event_SelectScriptEntryAndRefreshSessions(unsigned short);
// Original: arm9/ov001 @ 0x02154DE4; symbol: QueueObjectHalfword4AAfterStateChecks; size: 0x5C.
// Runs connection/object gates and setup, then queues object halfword +0x4A; returns 0x11 for the blocked gate or 4 on queue path.
extern "C" int QueueObjectHalfword4AAfterStateChecks(unsigned char *object) {
    if (Network_IsSessionActive(Network_GetConnectionManager())) {
        void *gameState = _ZN9GameState11GetInstanceEv();
        int index = GameState_ReadFirstObjectIndex(gameState);
        Network_QueuePartyControlLock(1, index & 0xff, object[0x108]);
    }
    if (Filesystem_QueuePendingLoadsInBatchesOfFive(object))
        return 0x11;
    Event_InstantiateLoadedSceneObjects(object);
    Event_SelectScriptEntryAndRefreshSessions(*(unsigned short *)(object + 0x4a));
    return 4;
}
