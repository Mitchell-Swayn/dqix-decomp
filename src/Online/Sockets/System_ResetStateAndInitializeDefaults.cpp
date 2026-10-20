#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void *, int, unsigned int);
extern "C" void Network_AttachSocketToCurrentThread(unsigned int);
// Original: arm9/ov031 @ 0x02217F44; symbol: func_ov031_02217f44; size: 0x58.
extern "C" void System_ResetStateAndInitializeDefaults(unsigned char *state) {
    VectorizedMemset(state + 0x1138, 0, 0x64);
    *(unsigned int *)(state + 0x1174) = 0xB68;
    *(unsigned int *)(state + 0x1178) = *(unsigned int *)(state + 0x19CC);
    *(unsigned int *)(state + 0x1180) = 0x5EA;
    *(unsigned int *)(state + 0x1184) = *(unsigned int *)(state + 0x19D0);
    Network_AttachSocketToCurrentThread((unsigned int)(state + 0x1138));
}
