#include <globaldefs.h>
extern "C" void Graphics_ConfigureProfilePageLayout(void*, unsigned int, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void ProfileEditor_AppendPhraseCategoryChoices(void*, void*, int);
extern "C" void Window_PushTextCanvas(void*, void*, int, int, int, int, int, int);
// Build a profile-screen text page in its shared buffer, then attach it to the UI.
// Original: arm9/ov012 @ 0x021898BC; symbol: func_ov012_021898bc; size: 0x78.
extern "C" void Graphics_BuildProfileRecordPage(unsigned char* screen) {
    Graphics_ConfigureProfilePageLayout(screen, screen[0x1371], 20, 1);
    memset(*(void**)(screen + 0x1374), 0, 0x960);
    ProfileEditor_AppendPhraseCategoryChoices(screen, *(void**)(screen + 0x1374), 0);
    Window_PushTextCanvas(screen + 0xac, *(void**)(screen + 0x1374), 0, 1, 0, 1, 0, 0);
}
