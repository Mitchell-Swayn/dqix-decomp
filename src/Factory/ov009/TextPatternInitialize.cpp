#include "TextPattern.h"

extern "C" int func_020424e4(const char*, int);

// Fifteen fixed-width source strings converted to encoded bytes by the
// initializer. The four-character entry uses all five bytes including its NUL.
// The final byte is the observed padding up to the next four-byte boundary.
struct TextSyntaxSource {
    char entries[15][5];
    unsigned char alignmentPadding;
};

extern "C" const TextSyntaxSource data_ov009_0218aafc = {
    { ":", "[", "]", "{", "}", "^", "-", ".", "$", "/", "@", "&", ",", "<c/>", "'" },
    0
};

extern "C" void func_ov009_021847ec(TextPatternContext* context)
{
    memset(&context->patternTable, 0, sizeof(context->patternTable));
    context->textData = 0;
    context->textDataSize = 0;
    int i;
    unsigned char* destination = context->syntax;
    for (i = 0; i < 15; ++i, ++destination)
        *destination = func_020424e4(data_ov009_0218aafc.entries[i], 1);
}
