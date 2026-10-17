#include <globaldefs.h>
extern "C" void AppendFiveFormattedArguments(void*, int, int, int, int, int),TextMarkup_AppendCursorTag(void*, int),Text_AppendFormattedIntegerAndStringFragment(void*, int, const void*),AppendFormatText(void*, const void*),Text_AppendFormattedIntegerFragmentAt020EFF74(void*,int);
extern "C" const void* FindRecordValueByKeyOrZero(void*, short);
struct ProfilePageBits { unsigned short index : 5; unsigned short value : 11; };
extern "C" void* ReadWordFieldAtOffset1C(void*);
extern "C" void SetOneOfSixteenWordFieldsAtOffset8B0(void*,int,int),WriteBoundedIndexedByteAt902(void*,int,int),Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(void*,int,int),TextMarkup_AppendSizeTag(void*,int),AppendTextByType(void*,int),AppendFormattedPair_Main02041A90(void*,int,int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const void*,int);
// Apply alternate page formatting, then center its localized caption.
// Original: arm9/ov012 @ 0x0218A2B8; symbol: func_ov012_0218a2b8; size: 0xBC.
extern "C" void func_ov012_0218a2b8(unsigned char* screen, void* output, int) {
    if (!output) return;
    ReadWordFieldAtOffset1C(screen);
    if (screen[0x1371] == 8) AppendTextByType(output, 4);
    Text_AppendFormattedIntegerAndStringFragment(output, 0, FindRecordValueByKeyOrZero(screen + 0x133c, (short)(screen[0x13fe] + 19)));
    if (screen[0x1371] == 8) AppendTextByType(output, 0);
    const void* caption = FindRecordValueByKeyOrZero(screen + 0x133c, 41);
    int textWidth = TextLayout_ComputeWidthWithGlyphSpacing(caption, 0);
    AppendFormattedPair_Main02041A90(output, (72 - textWidth) >> 1, 1);
    AppendFormatText(output, caption);
}
