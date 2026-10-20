#include <globaldefs.h>
ARM
// Original: arm9/ov003:0215eeb8; Encodes text as glyph IDs, maps the sequence into the output buffer, and returns status 8 or 9.
#include <std_library_functions.h>
extern "C" void __clear(void *, unsigned int);
extern "C" int Text_EncodeGlyphIndices(const char *, unsigned char *, unsigned int);
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char *, unsigned char *, unsigned int);
extern "C" int Graphics_EncodeTextToGlyphSequences(void *record) {
 unsigned char temp[0x100];
 volatile unsigned char *output = *(unsigned char **)((char *)record + 8);
 unsigned char mode = *((unsigned char *)record + 0x1f);
 __clear(temp, 0x100);
 int length = Text_EncodeGlyphIndices((const char *)output, temp, mode);
 if (length == 0) return 9;
 temp[length - 1] = 0;
 memset((void *)output, 0, *(unsigned int *)((char *)record + 0x10));
 Text_MapInputBytesToVariableLengthOutputSequences(temp, (unsigned char *)output, mode);
 return 8;
}
