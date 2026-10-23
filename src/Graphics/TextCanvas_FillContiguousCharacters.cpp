#include <globaldefs.h>
// Community C reference: ntrtwl/NitroSystem@d636fb5d2b212e8736f09859fff447be2bd0ac85
// libraries/g2d/src/g2d_CharCanvas.c (ClearContinuous and its inline helpers).
#pragma optimization_level 4
typedef unsigned long u32;
typedef unsigned char u8;
struct NNSiG2dCharCanvasVTable;
struct NNSG2dCharCanvas {
    u8* charBase;
    int areaWidth;
    int areaHeight;
    u8 dstBpp;
    u8 reserved[3];
    u32 param;
    const NNSiG2dCharCanvasVTable* vtable;
};
extern "C" void MIi_CpuClearFast(unsigned int data, void* destination, unsigned int size);
#pragma always_inline on
static inline int GetCharacterSize(const NNSG2dCharCanvas* pCC)
{
    return 8 * 8 * pCC->dstBpp / 8;
}
static inline u32 SpreadColor32(const NNSG2dCharCanvas* pCC, int cl)
{
    u32 val = (u32)cl;
    if (pCC->dstBpp == 4) {
        val = (val << 4) | val;
        val |= val << 8;
        val |= val << 16;
    } else {
        val = (val << 8) | val;
        val |= val << 16;
    }
    return val;
}
static inline void CpuFillFast(void* pDest, u32 data, u32 size)
{
    MIi_CpuClearFast(data, pDest, size);
}
// Original: arm9/main @ 0x020B18E8; symbol: func_020b18e8; size: 0x50.
extern "C" ARM void TextCanvas_FillContiguousCharacters(const NNSG2dCharCanvas* pCC,int cl) {
 u32 data=SpreadColor32(pCC,cl);
 CpuFillFast(pCC->charBase,data,(u32)pCC->areaWidth*pCC->areaHeight*GetCharacterSize(pCC));
}
