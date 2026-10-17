#include <globaldefs.h>
extern "C" void Graphics_ConfigureProfilePageLayout(void*, unsigned int, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void func_ov012_0218a9ec(void*, void*, int);
extern "C" void func_0205d304(void*, void*, int, int, int, int, int, int);
// Build this profile text page and attach it with its page-specific UI options.
// Original: arm9/ov012 @ 0x0218A974; symbol: func_ov012_0218a974; size: 0x78.
extern "C" void func_ov012_0218a974(unsigned char* screen) {
    Graphics_ConfigureProfilePageLayout(screen, screen[0x1371], 16, 1);
    memset(*(void**)(screen + 0x1374), 0, 0x960);
    func_ov012_0218a9ec(screen, *(void**)(screen + 0x1374), 0);

    func_0205d304(screen + 0xac, *(void**)(screen + 0x1374), 0, 1, 0, 1, 0, 0);
}
