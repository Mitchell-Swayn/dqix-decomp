#include <globaldefs.h>
extern "C" void Graphics_ConfigureProfilePageLayout(void*, unsigned int, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void func_ov012_0218a4b0(void*, void*, int);
extern "C" void func_0205d304(void*, void*, int, int, int, int, int, int);
// Build a profile-screen text page in its shared buffer, then attach it to the UI.
// Original: arm9/ov012 @ 0x0218A438; symbol: func_ov012_0218a438; size: 0x78.
extern "C" void func_ov012_0218a438(unsigned char* screen) {
    Graphics_ConfigureProfilePageLayout(screen, screen[0x1371], 21, 1);
    memset(*(void**)(screen + 0x1374), 0, 0x960);
    func_ov012_0218a4b0(screen, *(void**)(screen + 0x1374), 0);
    func_0205d304(screen + 0xac, *(void**)(screen + 0x1374), 0, 1, 0, 1, 0, 0);
}
