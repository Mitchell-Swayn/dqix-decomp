#include <globaldefs.h>
// Community C reference: ntrtwl/NitroSystem@d636fb5d2b212e8736f09859fff447be2bd0ac85
// libraries/g2d/src/g2d_CharCanvas.c, DrawGlyphLine and its inline accessors.
#pragma optimization_level 4
#pragma optimize_for_size off
#pragma always_inline on
typedef unsigned long u32;typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;
struct NNSiG2dCharCanvasVTable;
struct NNSG2dCharCanvas {u8* charBase;int areaWidth,areaHeight;u8 dstBpp;u8 reserved[3];u32 param;const NNSiG2dCharCanvasVTable* vtable;};
struct NNSG2dCharWidths{s8 left;u8 glyphWidth;s8 charWidth;};
struct NNSG2dFontGlyph{u8 cellWidth,cellHeight;u16 cellSize;s8 baselinePos;u8 maxCharWidth,bpp,flags;u8 glyphTable[1];};
struct NNSG2dFontWidth;struct NNSG2dFontCodeMap;
struct NNSG2dFontInformation{u8 fontType;s8 linefeed;u16 alterCharIndex;NNSG2dCharWidths defaultWidth;u8 encoding;NNSG2dFontGlyph* pGlyph;NNSG2dFontWidth* pWidth;NNSG2dFontCodeMap* pMap;};
struct NNSG2dFont{NNSG2dFontInformation* pRes;u16 (*cbCharSpliter)(const void**);};
struct NNSG2dGlyph{const NNSG2dCharWidths* pWidths;const u8* image;};
struct LC_INFO{const u8* dst;const u8* src;int ofs_x,ofs_y,width,height,dsrc,srcBpp,dstBpp;u32 cl;};
extern "C" void TextCanvas_BlitGlyphWithinTile(LC_INFO*);
static inline int GetCharacterSize(const NNSG2dCharCanvas* pCC){return 8*8*pCC->dstBpp/8;}
static inline u8 NNS_G2dFontGetCellHeight(const NNSG2dFont* pFont){return pFont->pRes->pGlyph->cellHeight;}
static inline u8 NNS_G2dFontGetCellWidth(const NNSG2dFont* pFont){return pFont->pRes->pGlyph->cellWidth;}
static inline u8 NNS_G2dFontGetBpp(const NNSG2dFont* pFont){return pFont->pRes->pGlyph->bpp;}
#define CHARACTER_WIDTH 8
#define CHARACTER_HEIGHT 8
// Draws a clipped glyph into a strided row-major grid of 8x8 character tiles.
// Font glyph-table storage is variable length; only the fixed record prefix and
// its first trailing byte are represented here, and no sizeof is used.
// Original: arm9/main @ 0x020B1540; symbol: func_020b1540; size: 0x198.
extern "C" void TextCanvas_DrawGlyphInRowMajorTiles (const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph)
{
    int ofs_x_base;
    int ofs_x;
    int ofs_y;
    int ofs_x_end;
    int ofs_y_end;
    unsigned int nextLineOffset;
    u8 * pChar;
    u8 glyphWidth;
    u8 charHeight;
    int charSize;

    charSize = GetCharacterSize(pCC);

    {
        int chara_x_num;
        int chara_y_num;
        const unsigned int areaWidth = (unsigned int)pCC->areaWidth;
        const unsigned int areaHeight = (unsigned int)pCC->areaHeight;
        u8 * const charBase = pCC->charBase;
        const NNSG2dCharWidths * const pWidth = pGlyph->pWidths;

        unsigned int chara_x_begin;
        unsigned int chara_x_last;
        unsigned int chara_y_begin;
        unsigned int chara_y_last;

        glyphWidth = pWidth->glyphWidth;
        charHeight = NNS_G2dFontGetCellHeight(pFont);

        if ( glyphWidth <= 0 ) {
            return;
        }

        if ((x + glyphWidth < 0) || (y + charHeight) < 0 ) {
            return;
        }

        chara_x_begin = (x <= 0) ? 0: ((u32)x / CHARACTER_WIDTH);
        chara_y_begin = (y <= 0) ? 0: ((u32)y / CHARACTER_HEIGHT);

        chara_x_last = (u32)(x + glyphWidth + (CHARACTER_WIDTH - 1)) / CHARACTER_WIDTH;
        if ( chara_x_last >= areaWidth ) {
            chara_x_last = areaWidth;
        }
        chara_y_last = (u32)(y + charHeight + (CHARACTER_HEIGHT - 1)) / CHARACTER_HEIGHT;
        if ( chara_y_last >= areaHeight ) {
            chara_y_last = areaHeight;
        }

        chara_x_num = (int)(chara_x_last - chara_x_begin);
        chara_y_num = (int)(chara_y_last - chara_y_begin);

        if ((chara_x_num < 0) || (chara_y_num < 0)) {
            return;
        }

        pChar = charBase + (pCC->param * chara_y_begin + chara_x_begin) * charSize;

        nextLineOffset = (pCC->param - chara_x_num) * charSize;

        ofs_x_base = (x < 0) ? x: x & 0x7;
        ofs_y = (y < 0) ? y: y & 0x7;
        ofs_x_end = ofs_x_base - CHARACTER_WIDTH * chara_x_num;
        ofs_y_end = ofs_y - CHARACTER_HEIGHT * chara_y_num;
    }

    {
        LC_INFO i;

        i.src = pGlyph->image;
        i.width = glyphWidth;
        i.height = charHeight;
        i.cl = (u32)(cl - 1);
        i.srcBpp = NNS_G2dFontGetBpp(pFont);
        i.dstBpp = pCC->dstBpp;
        i.dsrc = NNS_G2dFontGetCellWidth(pFont) * i.srcBpp;

        for ( ; ofs_y > ofs_y_end; ofs_y -= CHARACTER_HEIGHT) {
            i.ofs_y = ofs_y;
            for (ofs_x = ofs_x_base; ofs_x > ofs_x_end; ofs_x -= CHARACTER_WIDTH) {
                i.dst = pChar;
                i.ofs_x = ofs_x;
                TextCanvas_BlitGlyphWithinTile(&i);
                pChar += charSize;
            }
            pChar += nextLineOffset;
        }
    }
}
