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

extern "C" void CharacterCreation_DrawSelectionCorners(void *, int, int, int, int);
#define SUBMIT_AT(index, px, py) \
    sprites[index].x = px; sprites[index].y = py; \
    Graphics_SubmitTransformedCellToOam(graphics, sprites + index)
// Original: arm9/ov023 @ 0x021DA770; symbol: func_ov023_021da770; size: 0x244.
extern "C" void CharacterCreation_DrawSelectionSprites(void *owner)
{
    char *self = (char *)owner;
    int phase;
    unsigned flags = *(unsigned *)(self + 0xD9C);
    void *graphics = *(void **)(self + 0x7E4);
    CellSprite *sprites = *(CellSprite **)(self + 0x7E8);
    if (!(flags & 0x1000000)) {
        phase = *(signed char *)(self + 0xC58);
        if (!(phase == 9 && *(unsigned char *)(self + 0xC59) >= 1) && phase != 11 && !(flags & 0x400000)) {
            SUBMIT_AT(7, 0xE000, 0xA9000);
            SUBMIT_AT(6, 0x15000, 0xA9000);
            SUBMIT_AT(8, 0x3B000, 0xA9000);
            SUBMIT_AT(9, 0x8E000, 0xA9000);
            SUBMIT_AT(10, 0xC8000, 0xA9000);
        }
    }
    for (int i = 0; i < 8; ++i) {
        unsigned group = *(unsigned char *)(self + 0xDA3);
        if (i > *(signed char *)(self + 0xDA0 + group) - 1) break;
        unsigned x = (unsigned)(i * 16 + 120) * 4096;
        CellSprite *sprite = sprites + (i + 11);
        phase = *(signed char *)(self + 0xC58);
        unsigned palette = 10;
        if (phase == 9) {
            unsigned step = *(unsigned char *)(self + 0xC59);
            if (step >= 1 && step != 255) palette = 11;
        } else if (phase == 11) palette = 11;
        else if (i == phase - 1) palette = 9;
        sprite->palette = palette;
        sprite->x = x;
        sprite->y = 0x8000;
        Graphics_SubmitTransformedCellToOam(graphics, sprite);
    }
    if (*(unsigned char *)(self + 0xD94) == 1) return;
    phase = *(signed char *)(self + 0xC58);
    int spriteIndex = -1;
    int corners = 0;
    switch (phase) {
    case 2: case 3: case 4: case 5: case 6: case 7:
        spriteIndex = 20;
        if (phase == 2) spriteIndex = 19;
    case 1: case 8:
        corners = 1;
        break;
    }
    if (spriteIndex >= 0) {
        CellSprite *sprite = sprites + spriteIndex;
        short x = *(short *)(self + 0xC54);
        short y = *(short *)(self + 0xC56);
        sprite->x = (unsigned)x * 4096;
        sprite->y = (unsigned)y * 4096;
        Graphics_SubmitTransformedCellToOam(graphics, sprite);
    }
    if (!corners) return;
    if (*(unsigned *)(self + 0xD9C) & 0x400000) return;
    CharacterCreation_DrawSelectionCorners(self,
        *(short *)(self + 0xC4C), *(short *)(self + 0xC4E),
        *(short *)(self + 0xC50), *(short *)(self + 0xC52));
}
#undef SUBMIT_AT
