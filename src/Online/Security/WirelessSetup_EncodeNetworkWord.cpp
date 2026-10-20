#include <globaldefs.h>
THUMB
// Original: arm9/ov031 @ 0x0221E5D0; symbol: ReverseByteOrder; behavior follows recorded disassembly.
extern "C" unsigned int WirelessSetup_EncodeNetworkWord(unsigned int value) {  return ((value >> 24) & 255u) | ((value >> 8) & 0xff00u) | ((value << 8) & 0xff0000u) | ((value << 24) & 0xff000000u); }
