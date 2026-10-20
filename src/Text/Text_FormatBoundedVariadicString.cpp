#include <globaldefs.h>
extern "C" void Text_FormatBoundedOutputWithArgumentList(void*, unsigned, unsigned, const void*);
// The argument stream follows the third word and is rounded to word alignment.
// Original: arm9/main @ 0x020C7170; symbol: func_020c7170; size: 0x28.
extern "C" void Text_FormatBoundedVariadicString(void* a, unsigned b, unsigned c, ...)
{
    const void* args = (const void*)(((unsigned)&c & ~3u) + 4);
    Text_FormatBoundedOutputWithArgumentList(a, b, c, args);
}
