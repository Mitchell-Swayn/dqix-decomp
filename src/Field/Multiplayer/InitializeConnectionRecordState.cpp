#include <globaldefs.h>
ARM

struct Pool;
extern "C" void *Network_GetConnectionManager();
extern "C" void GameResources_SetPrimaryFlags(unsigned int *word, unsigned int mask);
extern "C" void Network_ClearMemberDisconnectFlag(unsigned char *p, int key);
extern "C" void *Network_GetCommandRecordPool();
extern "C" void Network_InitializeRecordPoolAndPeerBuffers(Pool *p);

// Original: arm9/ov017 @ 0x02195618; symbol: func_ov017_02195618; size: 0x40.
extern "C" void InitializeConnectionRecordState(unsigned int *object) {
    void *connection = Network_GetConnectionManager();
    GameResources_SetPrimaryFlags(object, 2);
    *(unsigned char *)((char *)object + 0x42e2) = 1;
    Network_ClearMemberDisconnectFlag((unsigned char *)connection, 0);
    Network_InitializeRecordPoolAndPeerBuffers((Pool *)Network_GetCommandRecordPool());
}
