#include <globaldefs.h>
extern "C" void Graphics_ConfigureProfilePageLayout(void*, unsigned int, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void func_ov012_0218a5f0(void*, void*, int);
extern "C" void func_0205d304(void*, void*, int, int, int, int, int, int);
// Build this profile text page and attach it with its page-specific UI options.
// Original: arm9/ov012 @ 0x0218A574; symbol: func_ov012_0218a574; size: 0x7C.
extern "C" void func_ov012_0218a574(unsigned char* screen) {
    Graphics_ConfigureProfilePageLayout(screen, screen[0x1371], 15, 1);
    memset(*(void**)(screen + 0x1374), 0, 0x960);
    func_ov012_0218a5f0(screen, *(void**)(screen + 0x1374), 0);

    func_0205d304(screen + 0xac, *(void**)(screen + 0x1374), 0, 0, 1, 1, 0, 0);
}
