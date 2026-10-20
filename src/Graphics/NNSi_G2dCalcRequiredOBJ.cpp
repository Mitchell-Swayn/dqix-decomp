// Community C reference: ntrtwl/NitroSystem@d636fb5d2b212e8736f09859fff447be2bd0ac85
// libraries/g2d/src/g2d_CharCanvas.c; only release assertions omitted and current ABI retained.
typedef unsigned long u32;
// Original: arm9/main @ 0x020B2054; symbol: func_020b2054; size: 0x5C.
// Nintendo NNSi_G2dCalcRequiredOBJ counts OAM entries for a rectangle measured in characters.
extern "C" int NNSi_G2dCalcRequiredOBJ (int areaWidth, int areaHeight)
{
    const u32 w = (unsigned int)areaWidth;
    const u32 h = (unsigned int)areaHeight;
    const u32 w8 = w / 8;
    const u32 h8 = h / 8;
    const u32 w4 = (w & 4) >> 2;
    const u32 h4 = (h & 4) >> 2;
    const u32 wcp = ((w & 2) >> 1) + (w & 1);
    const u32 hcp = ((h & 2) >> 1) + (h & 1);
    int ret = 0;


    ret += w8 * h8;
    ret += (wcp * 2 + w4) * h8;
    ret += (hcp * 2 + h4) * w8;
    ret += (wcp + w4) * (hcp + h4);

    return ret;
}
