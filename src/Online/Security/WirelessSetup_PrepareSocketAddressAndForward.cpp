#include <globaldefs.h>
THUMB
extern "C" void Network_BindSocketAddress(unsigned int, unsigned char *, unsigned int);
// Original: arm9/ov031 @ 0x0221E5BC; symbol: WriteByteAndForwardWithSwappedHalfwordField; size: 0xC.
// Stores the third argument's low byte through the second pointer, then forwards all arguments.
extern "C" void WirelessSetup_PrepareSocketAddressAndForward(unsigned int a, unsigned char *p, unsigned int value) {
    *p = (unsigned char)value;
    Network_BindSocketAddress(a, p, value);
}
