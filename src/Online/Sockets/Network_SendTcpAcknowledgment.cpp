#include <globaldefs.h>
ARM
extern "C" void Network_SendTcpControlOrRequestArp(void *, unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x02201F84; symbol: func_ov031_02201f84; size: 0x14.
extern "C" void Network_SendTcpAcknowledgment(void *p, unsigned int value) { Network_SendTcpControlOrRequestArp(p, 0x10, value); }
