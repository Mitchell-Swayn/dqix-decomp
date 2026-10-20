#include <globaldefs.h>
ARM
struct Entry { unsigned *data; };
extern "C" Entry *ZoneState2754_FindPrimaryRecordByKey(void *, int);
extern "C" void __clear(void *, unsigned);
extern "C" char* strcpy(char *, const char *);
extern "C" int sprintf(char *, const char *, ...);
// Original data: arm9/ov015 @ 0x219400a; symbol: data_ov015_0219400a.
// Source-defined character literal. Text: "md". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "md".
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern "C" const char ResourceFormatCharacterViewerResourceName_TextMd[];
// Original data: arm9/ov015 @ 0x219400d; symbol: data_ov015_0219400d.
// Source-defined character literal. Text: "mp". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "mp".
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern "C" const char ResourceFormatCharacterViewerResourceName_TextMp[];
// Original data: arm9/ov015 @ 0x2194010; symbol: data_ov015_02194010.
// Source-defined character literal. Text: "wp". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "wp".
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern "C" const char ResourceFormatCharacterViewerResourceName_TextWp[];
extern "C" const char Resource_FormatCharacterViewerResourceName_FormatS02D02DC[];
// Original: arm9/ov015 @ 0x0218C274; symbol: func_ov015_0218c274; size: 0x130.
extern "C" void Resource_FormatCharacterViewerResourceName(void *p, char *out, int flag) {
    int key = (short)*(unsigned int*)((char*)*(void**)((char*)p + 0x20) + 0x20);
    Entry *a = ZoneState2754_FindPrimaryRecordByKey((char*)*(void**)p + 0x4c, key);
    int key2 = (short)**(unsigned int**)((char*)p + 0x20);
    Entry *b = ZoneState2754_FindPrimaryRecordByKey((char*)*(void**)p + 0x4c, key2);
    unsigned int va = 0;
    unsigned int vb = 0;
    if (b) va = (b->data[1] << 12 >> 24);
    if (a) vb = (a->data[1] << 12 >> 24);
    char temp[4];
    __clear(temp, 4);
    int suffix;
    if (((unsigned char*)p)[0x1c] == 1) {
        strcpy(temp, ResourceFormatCharacterViewerResourceName_TextMd);
        suffix = ((unsigned char*)p)[0x3b] == 0 ? 0x6d : 0x77;
    } else {
        strcpy(temp, ResourceFormatCharacterViewerResourceName_TextMp);
        suffix = *(void**)((char*)p + 0x48) == 0 ? 0x6e : 0x62;
        if (flag) suffix = 0x66;
    }
    if ((suffix == 0x6e || suffix == 0x66) && ((unsigned char*)p)[0x3b] == 1)
        strcpy(temp, ResourceFormatCharacterViewerResourceName_TextWp);
    sprintf(out, Resource_FormatCharacterViewerResourceName_FormatS02D02DC, temp, va, vb, suffix);
}
