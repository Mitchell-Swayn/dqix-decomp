#include <globaldefs.h>
// Sets the palette index (top 4 bits) of every tile in a rectangle of a tile map.
struct TileMap {
    short width;
    short height;
    unsigned char unknown_4[8];
    unsigned short* tiles;
};

// Original: arm9/main @ 0x0204AE7C; symbol: func_0204ae7c; size: 0x98.
extern "C" ARM void TileMap_SetRectanglePaletteIndex(TileMap* map, unsigned short palette, short x, short y, short w, short h) {
    unsigned short* tiles = map->tiles;
    if (!tiles) return;
    palette &= 0xf;
    unsigned short shifted = palette << 12;
    short xEnd = x + w;
    short yEnd = y + h;
    short width = map->width;

    for (; y < yEnd; y++) {
        unsigned short* tile = tiles + width * y + x;
        for (short xi = x; xi < xEnd; xi++) {
            *tile &= 0xfff;
            *tile |= shifted;
            tile++;
        }
    }
}
