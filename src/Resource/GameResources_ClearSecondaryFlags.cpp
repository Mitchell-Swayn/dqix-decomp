#include <globaldefs.h>
// func_0203b4e8: 0x0203b4e8–0x0203b4fc, arm; 20 bytes
// Original: arm9/main @ 0x0203B4E8; symbol: func_0203b4e8; size: 0x14.
extern "C" void GameResources_ClearSecondaryFlags(int self, unsigned int mask) {
    *(unsigned int*)(self + 4) &= ~mask;
}
