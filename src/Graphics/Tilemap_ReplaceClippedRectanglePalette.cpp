#pragma opt_unpromotetypes on
#include <globaldefs.h>
struct TilemapOwner { unsigned int field0[5]; unsigned short* tiles; };
// Original: arm9/main @ 0x0204B9B8; symbol: func_0204b9b8; size: 0xFC.
// Replaces palette bits in a clipped 32-column,25-row tilemap rectangle.
extern "C" void Tilemap_ReplaceClippedRectanglePalette(TilemapOwner* owner, short x, short y, short width, short height, unsigned int palette)
{
    unsigned short* map = owner->tiles;
    if (!map) return;
    int right, bottom;
    if ((right = x + width) < 0) return;
    if ((bottom = y + height) < 0) return;
    if (x >= 32 || y >= 25) return;
    if (palette > 15) return;
    if (x < 0) { width += x; x = 0; }
    else if (right >= 32) width = 32 - x;
    if (y < 0) { height += y; y = 0; }
    else if (bottom >= 25) height = 25 - y;
    unsigned short* rowMap = map + y * 32 + x;
    palette = (unsigned short)(palette << 12);
    for (unsigned short row = 0; row < height; ++row) {
        for (unsigned short col = 0; col < width; ++col) {
            rowMap[col] &= 0xfff;
            rowMap[col] |= palette;
        }
        rowMap += 32;
    }
}
