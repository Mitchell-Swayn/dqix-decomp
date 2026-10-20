#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char* object);
extern "C" int Menu_BindSharedTextCanvas(char* obj, short a, short b, short c, short d);
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" void* __clear(void* destination, unsigned int count);
extern "C" void Text_FormatAndConditionallyUppercaseOutput(const char* format, char* out, int id);
extern "C" void TextMarkup_ExpandAndWrapText(void* p, int unused, void* a, void* b, int c, int d, unsigned flags);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char* text, int font);
extern "C" {
typedef void TextCanvas_RenderStyledTextAndMeasure_Fn(void*, int, int, char*, unsigned char, unsigned char, short*, short*, int);
extern TextCanvas_RenderStyledTextAndMeasure_Fn TextCanvas_RenderStyledTextAndMeasure;
}
extern "C" unsigned Menu_UploadSharedTextCanvas(char* canvas, unsigned offset, unsigned short palette, int layer);
extern "C" void Graphics_RenderOrAppendSharedCanvasText(char* self);
extern "C" char MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov023 @ 0x021DDE00; symbol: func_ov023_021dde00; size: 0x15c.
// Formats the pending item's name from *(self+0x50)+4, wraps it, centers it in a 0x70-pixel shared text canvas, uploads the canvas, and appends quantity text when flag 0x800 is set.
extern "C" void ItemDetail_RenderPendingItemName(char* self)
{
    if (*(char**)(self + 0x50)) {
        unsigned char canvas[224];
        TextCanvas_InitializeLayoutAndTransferDefaults(canvas);
        short height = 2;
        if (Menu_BindSharedTextCanvas((char*)canvas, 4, 1, 0xf, height)) {
            char* item = *(char**)(self + 0x50);
            if (*(char**)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage + 4) && item) {
                void* context = (void*)TextContext_GetSharedInstance();
                char wrapped[0x80];
                char formatted[0x80];
                short measured_b;
                short measured_a;
                __clear(formatted, 0x80);
                __clear(wrapped, 0x80);
                Text_FormatAndConditionallyUppercaseOutput(*(const char**)(item + 4), formatted, 0);
                TextMarkup_ExpandAndWrapText(context, 0xa, formatted, wrapped, 0x100, 0, 0);
                int width = TextLayout_ComputeWidthWithGlyphSpacing(wrapped, 0);
                TextCanvas_RenderStyledTextAndMeasure(canvas, (0x70 - (short)width) << 15 >> 16, 3, wrapped, 0xa, 0xf, &measured_a, &measured_b, 0);
            }
            unsigned size = Menu_UploadSharedTextCanvas(
                (char*)canvas,
                *(unsigned*)(self + 0x75c),
                (unsigned short)*(unsigned*)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage + 0xc),
                0);
            *(unsigned*)(self + 0x75c) = *(unsigned*)(self + 0x75c) + size;
        }
    }
    if (*(unsigned short*)(self + 0x774) & 0x800) {
        Graphics_RenderOrAppendSharedCanvasText(self);
    }
}
