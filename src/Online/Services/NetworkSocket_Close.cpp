#include <globaldefs.h>
ARM
extern "C" void Network_RequestSocketClose(void);
// Original: arm9/ov031 @ 0x02207434; symbol: func_ov031_02207434; size: 0xC.
extern "C" void NetworkSocket_Close(void) {
    Network_RequestSocketClose();
}
