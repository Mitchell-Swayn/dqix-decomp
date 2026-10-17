#include <globaldefs.h>
#pragma optimize_for_size off
struct TextCanvasPixelSurface {
    unsigned int prefix[2];
    unsigned char* pixels;
    unsigned char reserved[0x9c];
    short tileWidth, tileHeight;
};
// Original: arm9/main @ 0x0204CC68; symbol: func_0204cc68; size: 0xF8.
// Fills an exclusive-end rectangle in the canvas's tile-major 4bpp pixel buffer.
extern "C" void TextCanvas_FillTiled4bppRectangle(TextCanvasPixelSurface* canvas, unsigned int color,
    short startX, short startY, short endX, short endY) {
    if (endX < 0 || endY < 0) return;
    short height = canvas->tileHeight << 3;
    short width = canvas->tileWidth << 3;
    if (endX > width) return;
    if (height < endY) return;
    if (startX == endX || startY == endY) return;
    unsigned char high = (color & 15) << 4;
    unsigned char low = color & 15;
    for (; startY < endY; startY++) {
        short row = startY >> 3;
        short rowOffset = (short)(startY & 7) << 2;
        int rowBase = row * canvas->tileWidth;
        for (short x = startX; x < endX; x++) {
            short tile = rowBase + (short)(x >> 3);
            short tileOffset = tile << 5;
            short column = (short)(x & 7) >> 1;
            short index = tileOffset + column;
            index += rowOffset;
            unsigned char* pixel = &canvas->pixels[index];
            if (x & 1) { *pixel &= 15; *pixel |= high; }
            else { *pixel &= 240; *pixel |= low; }
        }
    }
}
