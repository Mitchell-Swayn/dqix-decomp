#include <globaldefs.h>
// func_0203979c: 0x0203979c–0x020397ac, arm; 16 bytes
// Original: arm9/main @ 0x0203979C; symbol: func_0203979c; size: 0x10.
extern "C" void Object_SetUnsignedCharAtOffset1CE(int self, unsigned char mask) {
    *(unsigned char*)(self + 0x1ce) |= mask;
}
