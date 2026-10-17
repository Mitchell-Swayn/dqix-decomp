#include <globaldefs.h>
// func_020493b8: 0x020493b8–0x020493c8, arm; 16 bytes
// Original: arm9/main @ 0x020493B8; symbol: func_020493b8; size: 0x10.
extern "C" void WriteIndirectComponentByte1D(int self, unsigned char value) {
    int object = *(int*)(self + 0x13c);
        if (object != 0) {
            *(unsigned char*)(object + 0x1d) = value;
        }
}
