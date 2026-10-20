#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void* TextCanvas_FindDisplayPartByKey(void*,int);
extern "C" bool TextCanvas_IsReady(int);
extern "C" void TextCanvas_GetGroupEntryPixelPosition(void*,int,int,short*,short*);
extern "C" void Shop_SubmitInterfaceSpriteAtPosition(void*,int,int,unsigned,unsigned char);
// Original: arm9/ov003 @ 0x0217577C; symbol: func_ov003_0217577c; size: 0xE0.
// Draws increment and decrement sprites shifted by the active quantity-control flags.
extern "C" void Shop_DrawQuantityAdjustmentSprites(char* self)
{
    void* canvas = *(void**)(self + 0x89c);
    void* part = TextCanvas_FindDisplayPartByKey(canvas, 9);
    if (part && TextCanvas_IsReady((int)part)) {
        short x, y;
        int offset = 0;
        if (*(unsigned char*)(self + 0x104b)) offset = 1;
        TextCanvas_GetGroupEntryPixelPosition(canvas, 9, 0x58, &x, &y);
        Shop_SubmitInterfaceSpriteAtPosition(self, x + offset, y + offset, 0x1d, 0x1e);
        offset = 0;
        if (*(unsigned char*)(self + 0x104c)) offset = 1;
        TextCanvas_GetGroupEntryPixelPosition(canvas, 9, 0x59, &x, &y);
        Shop_SubmitInterfaceSpriteAtPosition(self, x + offset, y + offset, 0x1e, 0x1f);
    }
}
