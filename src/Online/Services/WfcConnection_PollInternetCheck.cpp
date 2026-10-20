#include <globaldefs.h>
ARM
extern "C" void *Network_GetConnectionWorkspace(unsigned mask);
extern "C" int Resource_ReadSharedPointerUnderMutex(void);
extern "C" unsigned Network_NormalizeWirelessProfileIndex(unsigned value);
extern "C" unsigned WfcNetCheck_GetResultCode(void);
extern "C" void WfcNetCheck_DestroySession(void);
// Original: arm9/ov031 @ 0x02215478; symbol: func_ov031_02215478; size: 0x6C.
extern "C" int WfcConnection_PollInternetCheck(void *state) {
    unsigned char *bytes = (unsigned char *)state;
    unsigned char *selected = (unsigned char *)Network_GetConnectionWorkspace(1);
    int status = Resource_ReadSharedPointerUnderMutex();
    if (status != 0) {
        unsigned value = Network_NormalizeWirelessProfileIndex(bytes[0xd0d]);
        if (selected[0x15] == value) *(unsigned *)(selected + 0x10) = WfcNetCheck_GetResultCode();
        WfcNetCheck_DestroySession();
        if (status == 11) return 15;
        *(bytes + 0x444 + (bytes[0xd13] << 2)) = 1;
        return 11;
    }
    return 14;
}
