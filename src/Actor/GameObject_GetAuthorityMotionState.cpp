#include <globaldefs.h>
ARM
#pragma optimization_level 3
extern "C" void *Network_GetConnectionManager(void);
extern "C" void GameResources_GetInstance(void);
extern "C" int Network_IsSessionActive(void *);
extern "C" int Network_IsParentOrOffline(void *);
extern "C" unsigned short *Network_GetReceivedMemberPacket(void *, int);
extern "C" int Network_GetLocalMemberId(void *);
// Original: arm9/main @ 0x020342AC; symbol: func_020342ac; size: 0x94.
extern "C" unsigned int GameObject_GetAuthorityMotionState(void *object) {
    void *state = Network_GetConnectionManager();
    GameResources_GetInstance();
    if (Network_IsSessionActive(state) != 0 && Network_IsParentOrOffline(state) != 0 &&
        Network_GetReceivedMemberPacket(state, *(short *)((char *)object + 4)) != 0) {
        short key = *(short *)((char *)object + 4);
        int mode = Network_GetLocalMemberId(state);
        if (mode != key) {
            unsigned int flag = *(volatile unsigned char *)((char *)object + 0xc1);
            unsigned int shifted = flag << 30;
            shifted = shifted >> 30;
            if ((shifted & 2) != 0) {
            unsigned short *record = Network_GetReceivedMemberPacket(state, *(short *)((char *)object + 4));
                return ((unsigned int)*record << 16) >> 24;
            }
        }
    }
    return *(unsigned char *)((char *)object + 0xbe);
}
