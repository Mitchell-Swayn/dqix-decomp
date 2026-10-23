#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original: arm9/ov031 @ 0x0223E38C; symbol: func_ov031_0223e38c; size: 0x48.
extern "C" int DlcDownload_CopyStringGroupWithZeroPadding(void* output, const void* input, int length)
{
    int index;
    int copied = 0;
    index = copied;
    char* destination = (char*)output;
    const char* source = (const char*)input;
    if (length > 0) do {
        if (*source) {
            ++copied;
            *destination++ = *source++;
        } else *destination++ = 0;
        ++index;
    } while (index < length);
    return copied;
}
