#include <globaldefs.h>
// Community C reference: ntrtwl/NitroSystem@d636fb5d2b212e8736f09859fff447be2bd0ac85
// libraries/g2d/src/g2d_CharCanvas.c, LetterChar and its inline bit-reader initialization.
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
typedef unsigned long long u64;
struct BitReader {unsigned char* cursor;signed char remaining;unsigned char bits;};
extern "C" unsigned BitReader_ReadRequestedBitCount(BitReader*,int);
static inline void NNSi_G2dBitReaderInit(BitReader* reader,const void* src){reader->remaining=0;reader->cursor=(unsigned char*)src;reader->bits=0;}
static inline int MATH_IMax(int a,int b){return a>=b?a:b;}
static inline int MATH_IMin(int a,int b){return a<=b?a:b;}
#define CHARACTER_WIDTH 8
#define CHARACTER_HEIGHT 8
// Blits a packed glyph into one 4bpp or 8bpp tile, leaving zero source pixels
// transparent and adding the selected palette offset to nonzero pixels.
// BitReader keeps the existing owner-local type; it advances its cursor and
// remaining bits but does not mutate the bytes referenced by that cursor.
// Original: arm9/main @ 0x020B1300; symbol: func_020b1300; size: 0x240.
extern "C" void TextCanvas_BlitGlyphWithinTile (LC_INFO * i)
{
    const u8 * pSrc;
    u32 x_st;
    u32 x_ed;
    u32 y_st;
    u32 y_ed;
    u32 offset;



    {
        u32 bit_y_begin;

        x_st = (unsigned int)MATH_IMax(i->ofs_x, 0);
        y_st = (unsigned int)MATH_IMax(i->ofs_y, 0);
        x_ed = (unsigned int)MATH_IMin(CHARACTER_WIDTH, i->ofs_x + i->width);
        y_ed = (unsigned int)MATH_IMin(CHARACTER_HEIGHT, i->ofs_y + i->height);

        bit_y_begin = (unsigned int)-MATH_IMin(i->ofs_y, 0);
        offset = -MATH_IMin(i->ofs_x, 0) * i->srcBpp + bit_y_begin * i->dsrc;

        pSrc = i->src;
    }


    {
        u32 x;
        const int dsrc = i->dsrc;
        const int srcBpp = i->srcBpp;
        const int dstBpp = i->dstBpp;

        x_st *= dstBpp;
        x_ed *= dstBpp;

        if ( dstBpp == 4 ) {
            u32 * pDst = (u32 *)i->dst + y_st;
            u32 * pDstEnd = (u32 *)i->dst + y_ed;
            u32 cl = i->cl;

            for ( ; pDst < pDstEnd; pDst++) {
                BitReader reader;
                u32 out_line = *pDst;

                NNSi_G2dBitReaderInit(&reader, pSrc + offset / 8);
                (void)BitReader_ReadRequestedBitCount(&reader, (int)offset % 8);

                for (x = x_st; x < x_ed; x += 4) {
                    u32 bits = BitReader_ReadRequestedBitCount(&reader, srcBpp);

                    if ( bits != 0 ) {
                        out_line = (out_line & ~(0xF << x)) | ((cl + bits) << x);
                    }
                }

                *pDst = out_line;

                offset += dsrc;
            }
        } else {
            u32 * pDst = (u32 *)((u64 *)i->dst + y_st);
            u32 * const pDstEnd = (u32 *)((u64 *)i->dst + y_ed);
            u32 cl = i->cl;


            for ( ; pDst < pDstEnd; pDst += 2) {
                BitReader reader;
                u32 out_line_0 = *pDst;
                u32 out_line_1 = *(pDst + 1);

                NNSi_G2dBitReaderInit(&reader, pSrc + offset / 8);
                (void)BitReader_ReadRequestedBitCount(&reader, (int)offset % 8);

                for (x = x_st; x < x_ed; x += 8) {
                    u32 bits = BitReader_ReadRequestedBitCount(&reader, srcBpp);

                    if ( bits != 0 ) {
                        if ( x < 32 ) {
                            out_line_0 = (out_line_0 & ~((u32)0xFF << x)) | ((u32)(cl + bits) << x);
                        } else {
                            const u32 x_32 = x - 32;
                            out_line_1 = (out_line_1 & ~((u32)0xFF << x_32)) | ((u32)(cl + bits) << x_32);
                        }
                    }
                }

                *pDst = out_line_0;
                *(pDst + 1) = out_line_1;

                offset += dsrc;
            }
        }
    }
}
