#include <globaldefs.h>
// func_0203b4d8: 0x0203b4d8–0x0203b4e8, arm; 16 bytes
// Original: arm9/main @ 0x0203B4D8; symbol: func_0203b4d8; size: 0x10.
extern "C" void GameResources_SetSecondaryFlags(int self, unsigned int mask) {
    *(unsigned int*)(self + 4) |= mask;
}
