#include <globaldefs.h>
extern "C" void Graphics_ConfigureProfilePageLayout(void*, unsigned int, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void Graphics_AppendCenteredSummaryText(void*, void*, int);
extern "C" void Window_PushTextCanvas(void*, void*, int, int, int, int, int, int);
// Build this profile text page and attach it with its page-specific UI options.
// Original: arm9/ov012 @ 0x0218943C; symbol: func_ov012_0218943c; size: 0x78.
extern "C" void Graphics_BuildProfileSummaryPage(unsigned char* screen) {
    Graphics_ConfigureProfilePageLayout(screen, screen[0x1371], 2, 1);
    memset(*(void**)(screen + 0x1374), 0, 0x960);
    Graphics_AppendCenteredSummaryText(screen, *(void**)(screen + 0x1374), 0);

    Window_PushTextCanvas(screen + 0xac, *(void**)(screen + 0x1374), 0, 1, 0, 0, 0, 0);
}
