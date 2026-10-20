#include <globaldefs.h>
// func_0203b510: 0x0203b510–0x0203b520, arm; 16 bytes
// Original: arm9/main @ 0x0203B510; symbol: func_0203b510; size: 0x10.
extern "C" void GameResources_SetTertiaryFlags(int self, unsigned int mask) {
    *(unsigned int*)(self + 8) |= mask;
}
