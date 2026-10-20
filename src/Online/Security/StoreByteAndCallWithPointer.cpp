#include <globaldefs.h>
THUMB
ARM
extern "C" void NetworkSocket_SendToAddress(int, int, int, int, unsigned char *);
THUMB
// Original: arm9/ov031 @ 0x0221E5A0; symbol: func_ov031_0221e5a0; size: 0x10.
extern "C" void StoreByteAndCallWithPointer(int a0, int a1, int a2, int a3, unsigned char *valuePointer, unsigned int value) {
    *valuePointer = (unsigned char)value;
    NetworkSocket_SendToAddress(a0, a1, a2, a3, valuePointer);
}
