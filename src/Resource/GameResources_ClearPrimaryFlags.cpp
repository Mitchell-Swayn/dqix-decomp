#include <globaldefs.h>
// func_0203b4b0: 0x0203b4b0–0x0203b4c4, arm; 20 bytes
// Original: arm9/main @ 0x0203B4B0; symbol: func_0203b4b0; size: 0x14.
extern "C" void GameResources_ClearPrimaryFlags(unsigned int* word, unsigned int mask) {
    *word &= ~mask;
}
