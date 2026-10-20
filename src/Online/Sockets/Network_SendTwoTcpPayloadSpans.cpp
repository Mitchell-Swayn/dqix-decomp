#include <globaldefs.h>
ARM
extern "C" int Network_SendTcpSegmentsWithinPeerWindow(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x0220376C; symbol: func_ov031_0220376c; size: 0x3C.
extern "C" void Network_SendTwoTcpPayloadSpans(unsigned int first, unsigned int second, unsigned int left, unsigned int right, unsigned int mode, unsigned int value) {
    int valid = Network_SendTcpSegmentsWithinPeerWindow(first, second, mode, value);
    if (valid != 0 && right != 0) Network_SendTcpSegmentsWithinPeerWindow(left, right, mode, 0);
}
