#include <globaldefs.h>
ARM
extern "C" void Network_ShutdownSocketSend(void);
// Original: arm9/ov031 @ 0x02207428; symbol: func_ov031_02207428; size: 0xC.
extern "C" void NetworkSocket_Shutdown(void) {
    Network_ShutdownSocketSend();
}
