#include <globaldefs.h>
extern "C" void Graphics_ConfigureProfilePageLayout(void*, unsigned int, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void Text_AppendTwoRecordValuesWithCursorStyle(void*, void*, int);
extern "C" void Window_PushTextCanvas(void*, void*, int, int, int, int, int, int);
// Build a profile-screen text page in its shared buffer, then attach it to the UI.
// Original: arm9/ov012 @ 0x02189F38; symbol: func_ov012_02189f38; size: 0x78.
extern "C" void Graphics_BuildProfileValuePairPage(unsigned char* screen) {
    Graphics_ConfigureProfilePageLayout(screen, screen[0x1371], 25, 10);
    memset(*(void**)(screen + 0x1374), 0, 0x960);
    Text_AppendTwoRecordValuesWithCursorStyle(screen, *(void**)(screen + 0x1374), 0);
    Window_PushTextCanvas(screen + 0xac, *(void**)(screen + 0x1374), 0, 1, 0, 1, 0, 0);
}
