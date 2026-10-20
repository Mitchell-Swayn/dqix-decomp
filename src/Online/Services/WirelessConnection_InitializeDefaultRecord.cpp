#include <globaldefs.h>
ARM
extern "C" void WirelessConnection_InitializeRecord(void *, unsigned, unsigned, unsigned);
// Original: arm9/ov031 @ 0x02211C38; symbol: func_ov031_02211c38; size: 0x18.
extern "C" void WirelessConnection_InitializeDefaultRecord(void *object) {
    WirelessConnection_InitializeRecord(object, 3, 1, 0x14);
}
