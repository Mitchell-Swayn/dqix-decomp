#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
extern "C" unsigned int String_CountBytesUntilTerminator(const signed char *);
extern "C" int sprintf(char *, const char *, ...);
// Original data: arm9/ov023 @ 0x21fe144; symbol: data_ov023_021fe144.
// Source-defined character literal. Text: "%s". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "%s".
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" signed char FilesystemFormatInlinePathRecord_TextS[];
// Original: arm9/ov023 @ 0x021F2304; symbol: func_ov023_021f2304; size: 0x44.
extern "C" void Util_FormatUnsignedValueAtObjectOffsetC(void *obj, unsigned value) {
    if (value == 0) return;
    memset((char *)obj + 0xc, 0, 0x38);
    unsigned int length = String_CountBytesUntilTerminator((signed char *)obj + 0xc);
    sprintf((char *)obj + 0xc + length, (const char *)FilesystemFormatInlinePathRecord_TextS, value);
}
