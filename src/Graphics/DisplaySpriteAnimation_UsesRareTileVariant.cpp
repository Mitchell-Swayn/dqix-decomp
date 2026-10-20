#include <globaldefs.h>
// func_020de148: 0x020de148–0x020de154, arm; 12 bytes
// Original: arm9/main @ 0x020DE148; symbol: func_020de148; size: 0xC.
extern "C" unsigned char DisplaySpriteAnimation_UsesRareTileVariant(int self) {
    return *(unsigned char*)(self + 0x24) & 4;
}
