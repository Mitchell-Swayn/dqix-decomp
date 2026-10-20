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
// Original: arm9/ov002 @ 0x02168CA8; symbol: func_ov002_02168ca8; size: 0x68.
extern "C" void Util_InitializeFormattedTextRecord(char* p, char* source) {
    if (!source) return;
    unsigned int a = *(unsigned int*)source;
    *(unsigned int*)p = a;
    unsigned int b = *(unsigned int*)(source + 4);
    *(unsigned int*)(p + 4) = b;
    unsigned int c = *(unsigned int*)(source + 8);
    *(unsigned int*)(p + 4) = (unsigned int)(p + 0x44);
    *(unsigned int*)(p + 8) = c;
    const char* value = *(const char**)(source + 4);
    if (!value) return;
    memset(p + 0x44, 0, 0x200);
    unsigned int length = String_CountBytesUntilTerminator((signed char*)(p + 0x44));
    sprintf(p + 0x44 + length, (const char*)&UtilInitializeFormattedTextRecord_TextS, value);
}
