#pragma force_active on
extern "C" void Graphics_SubmitTransformedCellToOam(void *, void *);
namespace {
struct CellSprite {
    unsigned char preceding[20];
    unsigned x, y;
    unsigned char following[9];
    unsigned char palette;
    unsigned char ending[2];
};
typedef char CellSpriteStride[sizeof(CellSprite) == 40 ? 1 : -1];
}

extern "C" unsigned Grid_GetEntryCount(unsigned *);
// Original: arm9/ov023 @ 0x021DAB5C; symbol: func_ov023_021dab5c; size: 0xE4.
extern "C" void CharacterCreation_DrawSelectionCorners(void *owner, int left, int top, int width, int height)
{
    char *self = (char *)owner;
    unsigned x = (unsigned)left * 4096;
    unsigned y = (unsigned)top * 4096;
    unsigned leftCorner, topCorner, rightCorner, bottomCorner;
    unsigned right, bottom;
    unsigned heightValue = height;
    if (*(signed char *)(self + 0xC58) == 1) {
        bottom = y + heightValue * 4096;
        right = x + (unsigned)width * 4096;
        leftCorner = x - 0x7000;
        topCorner = y - 0x7000;
        rightCorner = right - 0x1000;
        bottomCorner = bottom - 0x1000;
        if (Grid_GetEntryCount((unsigned *)(self + 0xBEC)) == 8 && *(unsigned *)(self + 0xBF8) == 1) {
            leftCorner = x - 0x4000;
            topCorner = y - 0x4000;
            rightCorner = right - 0x4000;
            bottomCorner = bottom - 0x4000;
        }
    } else {
        right = x + (unsigned)width * 4096;
        bottom = y + heightValue * 4096;
        leftCorner = x - 0x4000;
        topCorner = y - 0x4000;
        rightCorner = right - 0x4000;
        bottomCorner = bottom - 0x4000;
    }
    CellSprite *sprites = *(CellSprite **)(self + 0x7E8);
    sprites[21].x = leftCorner;
    sprites[21].y = topCorner;
    sprites[22].x = rightCorner;
    sprites[22].y = topCorner;
    sprites[23].x = leftCorner;
    sprites[23].y = bottomCorner;
    sprites[24].x = rightCorner;
    sprites[24].y = bottomCorner;
    for (int i = 0; i < 4; ++i) {
        Graphics_SubmitTransformedCellToOam(*(void **)(self + 0x7E4), sprites + (i + 21));
    }
}
