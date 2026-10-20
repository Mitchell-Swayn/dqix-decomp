#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" unsigned GameState_ReadByteAtOffset4(void* state);
extern "C" void MapVRAMBanksToTextureImage(int banks);
extern "C" void _Z26InitializeTextureImageVRAMjb(unsigned id, bool enabled);
extern "C" void _Z28InitializeTexturePaletteVRAMjb(unsigned id, bool enabled);
// Original: arm9/ov017 @ 0x0218D274; symbol: func_ov017_0218d274; size: 0x50.
extern "C" void Graphics_InitializeTextureVRAMForGameState(void) {
    unsigned mode = GameState_ReadByteAtOffset4(_ZN9GameState11GetInstanceEv());
    if (mode == 6) {
        MapVRAMBanksToTextureImage(3);
        _Z26InitializeTextureImageVRAMjb(2, true);
    } else {
        MapVRAMBanksToTextureImage(15);
        _Z26InitializeTextureImageVRAMjb(4, true);
    }
    _Z28InitializeTexturePaletteVRAMjb(0x4000, true);
}
