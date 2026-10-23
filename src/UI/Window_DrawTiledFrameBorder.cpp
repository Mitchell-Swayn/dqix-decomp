#include <globaldefs.h>
struct WindowLayout { unsigned char pad[0x38]; unsigned char x,y,width,height; };
struct Window { void* staging; WindowLayout* layout; signed char count; };
extern "C" char* TextLayout_GetThirtyTwoByteFontEntry(int);
extern "C" void* __clear(void*,unsigned);
// Original caller ABI has two extra constant slots (8,15), unused by the fixed 8x8 blitter.
extern "C" void TextCanvas_BlitTransparentTile4Bpp(void*,const void*,short,short,int,int);
// Original data: arm9/main @ 0x020EE94C; symbol: data_020ee94c.
// Four corner glyph IDs: 0,2,5,7.
extern "C" unsigned char WindowDrawTiledFrameBorder_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x020E2110; symbol: func_020e2110; size: 0x200.
// Draws four corners and repeated edge glyphs into the window's tiled canvas.
extern "C" ARM void Window_DrawTiledFrameBorder(Window* window)
{
    WindowLayout* layout = window->layout;
    void* canvas = *reinterpret_cast<void**>(layout->pad + 4);
    int width = layout->width;
    int height = layout->height;
    char* first = TextLayout_GetThirtyTwoByteFontEntry(1);
    char* second = TextLayout_GetThirtyTwoByteFontEntry(6);
    int right;
    int bottom;
    if (first && second) {
        int last = width - 9;
        int x = 8;
        int i = 0;
        bottom = height - 8;
        for (; i < (last >> 3); ++i) {
            TextCanvas_BlitTransparentTile4Bpp(canvas, first, (short)x, 0, 8, 15);
            TextCanvas_BlitTransparentTile4Bpp(canvas, second, (short)x, bottom, 8, 15);
            x += 8;
        }
    }
    first = TextLayout_GetThirtyTwoByteFontEntry(3);
    second = TextLayout_GetThirtyTwoByteFontEntry(4);
    if (first && second) {
        int last = height - 9;
        int y = 8;
        int i = 0;
        right = width - 8;
        for (; i < (last >> 3); ++i) {
            TextCanvas_BlitTransparentTile4Bpp(canvas, first, 0, (short)y, 8, 15);
            TextCanvas_BlitTransparentTile4Bpp(canvas, second, right, (short)y, 8, 15);
            y += 8;
        }
    }
    short xs[4] = {0, (short)(width - 8), 0, (short)(width - 8)};
    short ys[4] = {0, 0, (short)(height - 8), (short)(height - 8)};
    for (int i = 0; i < 4; ++i) {
        char* pixels = TextLayout_GetThirtyTwoByteFontEntry(WindowDrawTiledFrameBorder_UnknownRoleInitializedBytes[i]);
        if (pixels) TextCanvas_BlitTransparentTile4Bpp(canvas, pixels, xs[i], ys[i], 8, 15);
    }
}
