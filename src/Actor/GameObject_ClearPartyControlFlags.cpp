#include <globaldefs.h>
// func_020397ac: 0x020397ac–0x020397c0, arm; 20 bytes
// Original: arm9/main @ 0x020397AC; symbol: func_020397ac; size: 0x14.
extern "C" void GameObject_ClearPartyControlFlags(int self, unsigned char mask) {
    *(unsigned char*)(self + 0x1ce) &= ~mask;
}
