#include <globaldefs.h>
ARM
extern "C" void ForwardVariadicArgumentsFromStack(void*,unsigned,unsigned,...);
extern "C" unsigned Util_CopyBytesToHalfwordsAndTerminate(unsigned short*,const char*,unsigned);
extern "C" void Graphics_DrawFixedWidthCenteredText(void*,int,int,int,int,const unsigned short*,unsigned);
extern "C" char data_ov031_0224bb7c[];
extern "C" char *data_ov031_02290ca0[];
// Original: arm9/ov031 @ 0x02230088; symbol: func_ov031_02230088; size: 0x98.
extern "C" void Graphics_DrawIpv4AddressRow(const unsigned char *address, int row) {
    unsigned short wideText[16];
    char text[16];
    ForwardVariadicArgumentsFromStack(text, 16, (unsigned)data_ov031_0224bb7c, address[0], address[1], address[2], address[3]);
    Util_CopyBytesToHalfwordsAndTerminate(wideText, text, 16);
    Graphics_DrawFixedWidthCenteredText(*(void**)(data_ov031_02290ca0[2] + 0x14), 95, row * 29 + 8, 2, 7, wideText, 1);
}
