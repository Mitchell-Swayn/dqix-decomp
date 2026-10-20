#include <globaldefs.h>
// func_020dde84: 0x020dde84–0x020dde90, arm; 12 bytes
// Original: arm9/main @ 0x020DDE84; symbol: func_020dde84; size: 0xC.
extern "C" void DisplaySpriteAnimation_SetOrigin(int self, unsigned int first, unsigned int second) {
    *(unsigned int*)(self + 8) = first;
        *(unsigned int*)(self + 0x0c) = second;
}
