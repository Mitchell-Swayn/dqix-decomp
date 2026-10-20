#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned int);
extern "C" unsigned int String_CountBytesUntilTerminator(const signed char*);
extern "C" int sprintf(char*, const char*, ...);
// Original data: arm9/ov002 @ 0x216d2fc; symbol: data_ov002_0216d2fc.
// Source-defined character literal. Text: "%s". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "%s".
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" unsigned int UtilInitializeFormattedTextRecord_TextS;
// Original: arm9/ov002 @ 0x02168D10; symbol: func_ov002_02168d10; size: 0x44.
extern "C" void PartyMenu_SetTitleNotificationHeading(char* object, const char* format) {
    if (format) {
        memset(object + 0xc, 0, 0x38);
        unsigned int length = String_CountBytesUntilTerminator((signed char*)(object + 0xc));
        sprintf(object + 0xc + length, (const char*)&UtilInitializeFormattedTextRecord_TextS, format);
    }
}
