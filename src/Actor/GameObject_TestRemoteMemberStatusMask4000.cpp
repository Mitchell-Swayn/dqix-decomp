#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int Network_GetConnectionManager(void);
extern "C" void GameResources_GetInstance(void);
extern "C" int Network_IsSessionActive(int);
extern "C" int Network_GetReceivedMemberPacket(int, int);
// Original: arm9/main @ 0x02034340; symbol: func_02034340; size: 0x60.
extern "C" int GameObject_TestRemoteMemberStatusMask4000(const char *object) {
    int handle = Network_GetConnectionManager();
    GameResources_GetInstance();
    int result = 0;
    if (Network_IsSessionActive(handle) != 0) {
        int id = *(const short *)(object + 4);
        if (Network_GetReceivedMemberPacket(handle, id) != 0) {
            id = *(const short *)(object + 4);
            int record = Network_GetReceivedMemberPacket(handle, id);
            unsigned int flag = *(const unsigned short *)(record + 2);
            if ((flag << 17) >> 31) {
                result = 1;
            }
        }
    }
    return result;
}
