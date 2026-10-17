#include <globaldefs.h>
ARM
extern "C" int AppendFormatText(char *p, const char *text);
// Original: arm9/ov023 @ 0x021E8CC0; symbol: func_ov023_021e8cc0; size: 0x1C.
extern "C" void func_ov023_021e8cc0(void *object) {
    const char *text = *(const char **)((char *)object + 0x5fc);
    if (text)
        AppendFormatText(*(char **)((char *)object + 0x5d8), text);
}
