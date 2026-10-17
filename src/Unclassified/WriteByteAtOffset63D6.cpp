#include <globaldefs.h>
// func_020115b4: 0x020115b4–0x020115c0, arm; 12 bytes
// Original: arm9/main @ 0x020115B4; symbol: func_020115b4; size: 0xC.
extern "C" void WriteByteAtOffset63D6(int self, unsigned char value) {
    *(unsigned char*)(self + 0x63d6) = value;
}
