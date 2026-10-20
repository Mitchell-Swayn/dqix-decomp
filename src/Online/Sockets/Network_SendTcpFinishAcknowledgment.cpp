#include <globaldefs.h>
ARM
extern "C" void Network_SendTcpControlOrRequestArp(void *, unsigned, unsigned);
// Original: arm9/ov031 @ 0x02201F98; symbol: func_ov031_02201f98; size: 0x14.
extern "C" void Network_SendTcpFinishAcknowledgment(void *object, unsigned value) {
    Network_SendTcpControlOrRequestArp(object, 0x11, value);
}
