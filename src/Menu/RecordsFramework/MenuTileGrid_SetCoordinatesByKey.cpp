#include <globaldefs.h>
ARM
extern "C" unsigned char *TileGrid_ResolveByKey(void *, void *);
// Original: arm9/ov023 @ 0x021F65B4; symbol: func_ov023_021f65b4; size: 0x20.
extern "C" void MenuTileGrid_SetCoordinatesByKey(void *a, void *b, unsigned short first, unsigned short second) {
    unsigned char *result = TileGrid_ResolveByKey(a, b);
    if (result) {
        *(unsigned short *)(result + 0x5c) = first;
        *(unsigned short *)(result + 0x5e) = second;
    }
}
