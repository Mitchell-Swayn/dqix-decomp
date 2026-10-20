#include <globaldefs.h>
struct TileMapSource { short width, height; char unknown[8]; const unsigned short* tiles; };
// Original: arm9/main @ 0x0204B620; symbol: func_0204b620; size: 0x258.
// Clips and copies a tilemap rectangle into a 32 by 25 destination, optionally overriding its palette.
extern "C" ARM void Graphics_CopyClippedTilemapRectangle(void* owner, volatile unsigned short* destination, const TileMapSource* source,
    short sourceX, short sourceY, short destinationX, short destinationY, short width, short height, unsigned short palette)
{
    if (!destination || !source) return;
    if (destinationX >= 32 || destinationY >= 25) return;
    if (destinationX + width <= 0 || destinationY + height <= 0) return;
    if (width <= 0 || height <= 0) return;
    short sourceWidth = source->width;
    short sourceHeight = source->height;
    if (sourceWidth <= sourceX || sourceHeight <= sourceY || sourceX + width <= 0 || sourceY + height <= 0) return;
    if (sourceX < 0) { destinationX -= sourceX; width += sourceX; sourceX = 0; }
    else if (sourceWidth < sourceX + width) width = sourceWidth - sourceX;
    if (sourceY < 0) { destinationY -= sourceY; height += sourceY; sourceY = 0; }
    else if (sourceHeight < sourceY + height) height = sourceHeight - sourceY;
    if (sourceWidth < width) width = sourceWidth;
    if (sourceHeight < height) height = sourceHeight;
    if (destinationX < 0) { sourceX -= destinationX; width += destinationX; destinationX = 0; }
    else if (destinationX + width > 32) width = 32 - destinationX;
    if (destinationY < 0) { sourceY -= destinationY; height += destinationY; destinationY = 0; }
    else if (destinationY + height > 25) height = 25 - destinationY;
    if (!source->tiles) return;
    const unsigned short* src = source->tiles + (sourceWidth * sourceY + sourceX);
    volatile unsigned short* dst = destination + destinationY * 32 + destinationX;
    if (palette != 0xffff) {
        for (unsigned short y = 0; y < height; ++y) {
            for (unsigned short x = 0; x < width; ++x) {
                dst[x] = src[x] & 0xfff;
                dst[x] |= (unsigned short)(palette << 12);
            }
            src += sourceWidth; dst += 32;
        }
    } else {
        for (unsigned short y = 0; y < height; ++y) {
            for (unsigned short x = 0; x < width; ++x) dst[x] = src[x];
            src += sourceWidth; dst += 32;
        }
    }
}
