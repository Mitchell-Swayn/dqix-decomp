#include <globaldefs.h>
ARM
#pragma force_active on
struct TextCanvasPixelSurface {
    unsigned int prefix[2];
    unsigned char* pixels;
    unsigned char reserved[0x9c];
    short tileWidth, tileHeight;
};
extern "C" void TextCanvas_FillTiled4bppRectangle(TextCanvasPixelSurface*, unsigned int, short, short, short, short);
// Original: arm9/main @ 0x0204F3BC; symbol: func_0204f3bc; size: 0x60.
// Draws a one-pixel separator with a one-pixel inset when its row is inside the canvas.
extern "C" void TextCanvas_DrawHorizontalSeparator(TextCanvasPixelSurface* canvas, short row)
{
    if (row < 0) return;
    short width = canvas->tileWidth * 8;
    short height = canvas->tileHeight * 8;
    if (row >= height) return;
    TextCanvas_FillTiled4bppRectangle(canvas, 15, 1, row, width - 1, row + 1);
}
