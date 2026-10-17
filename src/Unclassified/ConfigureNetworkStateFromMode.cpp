#include <globaldefs.h>
extern "C" unsigned char data_021015a0[];
extern "C" unsigned char data_021016e0[];
extern "C" void MI_CpuCopy8(const void *, void *, unsigned);
extern "C" int InvokeStoredCallbackAndStartFollowupOperation();
extern "C" int Network_BeginStateThreeOperationUnlessAlreadyActive();
// Original: arm9/main @ 0x0202DC40; symbol: func_0202dc40; size: 0x74.
extern "C" int ConfigureNetworkStateFromMode(unsigned mode, const void *payload) {
    *(unsigned *)(data_021015a0 + 0x2c) = 0x440;
    *(unsigned *)(data_021015a0 + 0x38) = 0x80;
    *(unsigned *)(data_021015a0 + 0x34) = mode;
    *(unsigned *)(data_021015a0 + 0x10) = 3;
    if (mode == 1 || mode == 3 || mode == 5) {
        MI_CpuCopy8(payload, data_021016e0, 0xc0);
        if (*(unsigned *)(data_021015a0 + 0x30)) return InvokeStoredCallbackAndStartFollowupOperation();
        return Network_BeginStateThreeOperationUnlessAlreadyActive();
    }
    return 0;
}
