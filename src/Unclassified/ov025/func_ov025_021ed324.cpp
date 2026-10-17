#include <globaldefs.h>
ARM
extern "C" char *strcpy(char *, const char *);
// Original: arm9/ov025 @ 0x021ED324; symbol: func_ov025_021ed324; size: 0x20.
extern "C" void func_ov025_021ed324(void *p, const char *src) {
    if (src)
        strcpy((char *)p + 0x16c, src);
    else
        *((char *)p + 0x16c) = 0;
}
