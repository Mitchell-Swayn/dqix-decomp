#include <globaldefs.h>
extern "C" void AppendFiveFormattedArguments(void*, int, int, int, int, int),TextMarkup_AppendCursorTag(void*, int),Text_AppendFormattedIntegerAndStringFragment(void*, int, const void*),AppendFormatText(void*, const void*),Text_AppendFormattedIntegerFragmentAt020EFF74(void*,int);
extern "C" const void* FindRecordValueByKeyOrZero(void*, short);
struct ProfilePageBits { unsigned short index : 5; unsigned short value : 11; };
// Render a two-label page with a special style when the value field is zero.
// Original: arm9/ov012 @ 0x0218A4B0; symbol: func_ov012_0218a4b0; size: 0xC4.
extern "C" void func_ov012_0218a4b0(unsigned char* screen, void* output, int reset) {
    if (!output) return;
    int style = *(int*)(screen + 0x13e8);
    if (reset) AppendFiveFormattedArguments(output, style, 8, 5, 5, 5);
    TextMarkup_AppendCursorTag(output, style);
    Text_AppendFormattedIntegerAndStringFragment(output, 0, FindRecordValueByKeyOrZero(screen + 0x133c, 10));
    AppendFormatText(output, *(const void**)(screen + 0x1378));
    if (!((ProfilePageBits*)(screen + 0x13c4))->value) Text_AppendFormattedIntegerFragmentAt020EFF74(output, 3);
    Text_AppendFormattedIntegerAndStringFragment(output, 1, FindRecordValueByKeyOrZero(screen + 0x133c, 11));
}
