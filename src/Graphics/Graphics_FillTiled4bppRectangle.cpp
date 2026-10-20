#include <globaldefs.h>

// Pixel storage and tile dimensions established from this routine and callers.
// Other members of the owning graphics object remain unreconstructed here.
struct TiledPixelSurface {
    unsigned char reserved0[8];
    unsigned char* pixels;
    unsigned char reservedC[0x9c];
    short widthTiles;
    short heightTiles;
};

// These local optimization settings retain the original 16-bit offset evaluation.
#pragma opt_common_subs off
#pragma always_inline on
static inline short ComputeTileColumnOffset(int row, int x) {
    short tile = row + (short)(x >> 3);
    return (short)(tile * 32);
}

// Original: arm9/main @ 0x0204F914; symbol: func_0204f914; size: 0xF8.
// Proposed name: Graphics_FillTiled4bppRectangle.
// Fills an exclusive-edge rectangle of palette indices in 8x8, 32-byte tiles.
// Bounds checks constrain only right/bottom; left/top are not independently clipped.
extern "C" void Graphics_FillTiled4bppRectangle(TiledPixelSurface* surface, int color,
                            int left, int top, int right, int bottom) {
    if (right < 0 || bottom < 0) return;
    short height = surface->heightTiles * 8;
    short width = surface->widthTiles * 8;
    if (right > width) return;
    if (height < bottom) return;
    if (left == right || top == bottom) return;

    unsigned char highColor = color & 15;
    unsigned char lowColor = highColor;
    highColor <<= 4;
    for (; top < bottom; top = (short)(top + 1)) {
        short rowByteOffset = (short)(top & 7) << 2;
        int tileRow = (short)(top >> 3) * surface->widthTiles;
        for (int x = left; x < right; x = (short)(x + 1)) {
            short byteOffset = ComputeTileColumnOffset(tileRow, x)
                             + ((short)(x & 7) >> 1);
            byteOffset += rowByteOffset;
            unsigned char& pixel = surface->pixels[byteOffset];
            // Keep clear/set as separate byte assignments: the compiler forwards
            // the byte store and produces the original narrowing temporary.
            if (x & 1) {
                pixel &= 15;
                pixel |= highColor;
            } else {
                pixel &= 0xf0;
                pixel |= lowColor;
            }
        }
    }
}
