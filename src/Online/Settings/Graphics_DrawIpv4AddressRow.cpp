#include <globaldefs.h>
ARM
extern "C" void Text_FormatBoundedVariadicString(void*,unsigned,unsigned,...);
extern "C" unsigned Util_CopyBytesToHalfwordsAndTerminate(unsigned short*,const char*,unsigned);
extern "C" void Graphics_DrawFixedWidthCenteredText(void*,int,int,int,int,const unsigned short*,unsigned);
extern "C" char Graphics_DrawIpv4AddressRow_Format3D3D3D3D[];
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02230088; symbol: func_ov031_02230088; size: 0x98.
extern "C" void Graphics_DrawIpv4AddressRow(const unsigned char *address, int row) {
    unsigned short wideText[16];
    char text[16];
    Text_FormatBoundedVariadicString(text, 16, (unsigned)Graphics_DrawIpv4AddressRow_Format3D3D3D3D, address[0], address[1], address[2], address[3]);
    Util_CopyBytesToHalfwordsAndTerminate(wideText, text, 16);
    Graphics_DrawFixedWidthCenteredText(*(void**)(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[2] + 0x14), 95, row * 29 + 8, 2, 7, wideText, 1);
}
