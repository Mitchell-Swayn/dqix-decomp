#include <globaldefs.h>
// Community C reference: ntrtwl/NitroSystem@d636fb5d2b212e8736f09859fff447be2bd0ac85
// libraries/g2d/src/g2d_CharCanvas.c, ClearAreaLine and its inline helpers.
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
#define MATH_ROUNDDOWN(x,a) ((x)&~((a)-1))
#define MATH_ROUNDUP(x,a) (((x)+(a)-1)&~((a)-1))
extern "C" void TextCanvas_FillRectangleWithinTile(void*,int,int,int,int,u32,int);
static inline u32 SpreadColor32(const NNSG2dCharCanvas* pCC,int cl){u32 val=(u32)cl;if(pCC->dstBpp==4){val=(val<<4)|val;val|=val<<8;val|=val<<16;}else{val=(val<<8)|val;val|=val<<16;}return val;}
// Fills the clipped subrectangle of each intersected row-major character tile.
// Original: arm9/main @ 0x020B19B8; symbol: func_020b19b8; size: 0x19C.
extern "C" void TextCanvas_FillRectangleInRowMajorTiles (const NNSG2dCharCanvas * pCC, int cl, int x, int y, int w, int h)
{
    int ix, iy;
    int cx, cy, cw, ch;
    const int xw = x + w;
    const int yh = y + h;
    u32 cl8;


    cl8 = SpreadColor32(pCC, cl);

    {
        const int left = MATH_ROUNDDOWN(x, CHARACTER_WIDTH);
        const int top = MATH_ROUNDDOWN(y, CHARACTER_HEIGHT);
        const int right = MATH_ROUNDUP(xw, CHARACTER_WIDTH);
        const int bottom = MATH_ROUNDUP(yh, CHARACTER_HEIGHT);

        const int charSize = GetCharacterSize(pCC);
        const int charBaseLineOffset = (int)(pCC->param * charSize);
        const int bpp = pCC->dstBpp;
        u8 * pCharBase;
        u8 * pChar;

        pCharBase = pCC->charBase + ((top / CHARACTER_HEIGHT) * pCC->param + (left / CHARACTER_WIDTH)) * charSize;

        for (iy = top; iy < bottom; iy += CHARACTER_HEIGHT) {
            cy = (iy < y) ? y - iy: 0;
            ch = ((yh - iy > CHARACTER_HEIGHT) ? CHARACTER_HEIGHT: yh - iy) - cy;
            pChar = pCharBase;

            for (ix = left; ix < right; ix += CHARACTER_WIDTH) {
                cx = (ix < x) ? x - ix: 0;
                cw = ((xw - ix > CHARACTER_WIDTH) ? CHARACTER_WIDTH: xw - ix) - cx;

                TextCanvas_FillRectangleWithinTile(pChar, cx, cy, cw, ch, cl8, bpp);
                pChar += charSize;
            }

            pCharBase += charBaseLineOffset;
        }
    }
}
