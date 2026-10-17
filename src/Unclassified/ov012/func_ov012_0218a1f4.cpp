#include <globaldefs.h>
extern "C" void AppendFiveFormattedArguments(void*, int, int, int, int, int),TextMarkup_AppendCursorTag(void*, int),Text_AppendFormattedIntegerAndStringFragment(void*, int, const void*),AppendFormatText(void*, const void*),Text_AppendFormattedIntegerFragmentAt020EFF74(void*,int);
extern "C" const void* FindRecordValueByKeyOrZero(void*, short);
struct ProfilePageBits { unsigned short index : 5; unsigned short value : 11; };
extern "C" void* ReadWordFieldAtOffset1C(void*);
extern "C" void SetOneOfSixteenWordFieldsAtOffset8B0(void*,int,int),WriteBoundedIndexedByteAt902(void*,int,int),Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(void*,int,int),TextMarkup_AppendSizeTag(void*,int),AppendTextByType(void*,int),AppendFormattedPair_Main02041A90(void*,int,int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const void*,int);
// Format a numeric profile value and center its localized caption.
// Original: arm9/ov012 @ 0x0218A1F4; symbol: func_ov012_0218a1f4; size: 0xC4.
extern "C" void func_ov012_0218a1f4(unsigned char* screen, void* output, int) {
    if (!output) return;
    void* formatter = ReadWordFieldAtOffset1C(screen);
    SetOneOfSixteenWordFieldsAtOffset8B0(formatter, 0, *(unsigned short*)(screen + 0x13fc));
    WriteBoundedIndexedByteAt902(formatter, 0, 4);
    Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(formatter, 0, 1);
    TextMarkup_AppendSizeTag(output, 12);
    short labelId = 100;
    if (screen[0x1371] == 7) labelId = 103;
    Text_AppendFormattedIntegerAndStringFragment(output, 0, FindRecordValueByKeyOrZero(screen + 0x133c, labelId));
    const void* caption = FindRecordValueByKeyOrZero(screen + 0x133c, 42);
    int textWidth = TextLayout_ComputeWidthWithGlyphSpacing(caption, 0);
    AppendFormattedPair_Main02041A90(output, (96 - textWidth) >> 1, 1);
    AppendFormatText(output, caption);
}
