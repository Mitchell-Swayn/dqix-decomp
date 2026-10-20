#include <globaldefs.h>
extern "C" int Network_GetConnectionManager(void);
extern "C" int Network_IsSessionActive(void);
extern "C" unsigned int Network_GetLocalMemberId(int);
extern "C" void NetworkOwnership_ReleaseForPeer(int, int, unsigned char);

// Original: arm9/main @ 0x020E3428; symbol: func_020e3428; size: 0x40.
extern "C" void NetworkOwnership_ReleaseForLocalPeer(int first, int second) {
    int value = Network_GetConnectionManager();
    if (Network_IsSessionActive() == 0) {
        return;
    }
    int mode = Network_GetLocalMemberId(value);
    NetworkOwnership_ReleaseForPeer(first, second, (unsigned char)mode);
}
