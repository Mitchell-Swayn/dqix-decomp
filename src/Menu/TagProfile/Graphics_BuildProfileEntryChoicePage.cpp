#include <globaldefs.h>
extern "C" void Graphics_ConfigureProfilePageLayout(void*, unsigned int, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void ProfileEditor_DrawKeyboard(void*, void*, int);
extern "C" void Window_PushTextCanvas(void*, void*, int, int, int, int, int, int);
// Build this profile text page and attach it with its page-specific UI options.
// Original: arm9/ov012 @ 0x0218AABC; symbol: func_ov012_0218aabc; size: 0x78.
extern "C" void Graphics_BuildProfileEntryChoicePage(unsigned char* screen) {
    Graphics_ConfigureProfilePageLayout(screen, screen[0x1371], 1, 3);
    memset(*(void**)(screen + 0x1374), 0, 0x960);
    ProfileEditor_DrawKeyboard(screen, *(void**)(screen + 0x1374), 0);

    Window_PushTextCanvas(screen + 0xac, *(void**)(screen + 0x1374), 0, 0, 0, 1, 0, 0);
}
