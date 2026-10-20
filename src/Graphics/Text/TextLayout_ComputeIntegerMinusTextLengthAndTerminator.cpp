#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void Text_ParseDelimitedSignedIntegerSequence(unsigned int, int *, int);
extern "C" int TextLookup_GetPackedFontMetrics(unsigned int);
// Original: arm9/main @ 0x0206B85C; symbol: func_0206b85c; size: 0x38.
extern "C" int TextLayout_ComputeIntegerMinusTextLengthAndTerminator(unsigned int arg0, int *result, unsigned int text, int initial) {
    int local;
    Text_ParseDelimitedSignedIntegerSequence(arg0, &local, 1);
    int length = TextLookup_GetPackedFontMetrics(text);
    *result = local - (length + 1);
    return 0;
}
