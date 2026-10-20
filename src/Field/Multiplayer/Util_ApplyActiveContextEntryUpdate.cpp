#include <globaldefs.h>
ARM
extern "C" int Network_GetLocalMemberId(char* p);
extern "C" bool Network_IsParentOrOffline(unsigned* p);
extern "C" void *NetworkOwnership_GetRegistry();
extern "C" char* NetworkOwnership_FindEntryByKey(unsigned char* p,int key);
extern "C" void NetworkOwnership_RequestForPeer(void* p,unsigned id,unsigned value);
extern "C" void NetworkOwnership_ReleaseForPeer(void *p,int id,int value);
// Original: arm9/ov017 @ 0x021CEB28; symbol: func_ov017_021ceb28; size: 0xA4.
extern "C" void Util_ApplyActiveContextEntryUpdate(int mode, unsigned char *input, int unused, int unused2, char *state) {
    unsigned char *context = (unsigned char*)NetworkOwnership_GetRegistry();
    if (Network_IsParentOrOffline((unsigned*)state) && mode > 0) {
        if (input[4]) {
            NetworkOwnership_RequestForPeer(context, input[5], input[7]);
            return;
        }
        NetworkOwnership_ReleaseForPeer(context, input[5], input[7]);
        return;
    } else if (mode == 0) {
        if (input[7] != Network_GetLocalMemberId(state)) return;
        char *entry = NetworkOwnership_FindEntryByKey(context, input[5]);
        if (!entry) return;
        if (input[4]) entry[2] = 1;
        else entry[2] = 3;
    }
}
