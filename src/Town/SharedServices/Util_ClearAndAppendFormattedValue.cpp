#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned);
extern "C" unsigned String_CountBytesUntilTerminator(const signed char*);
extern "C" int sprintf(char*, const char*, ...);
// Original data: arm9/ov003 @ 0x217fce0; symbol: data_ov003_0217fce0.
// Source-defined character literal. Text: "%s". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "%s".
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" const char UtilClearAndAppendFormattedValue_TextS[];
// Original: arm9/ov003 @ 0x02158140; symbol: func_ov003_02158140; size: 0x44.
extern "C" void Util_ClearAndAppendFormattedValue(signed char* object, int value) {
    if (!value) return;
    memset(object + 0xc, 0, 0x38);
    unsigned length = String_CountBytesUntilTerminator(object + 0xc);
    sprintf((char*)(object + 0xc) + length, UtilClearAndAppendFormattedValue_TextS, value);
}
