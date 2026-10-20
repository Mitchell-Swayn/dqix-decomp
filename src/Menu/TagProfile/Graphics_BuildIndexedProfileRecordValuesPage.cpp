#include <globaldefs.h>
extern "C" void Graphics_ConfigureProfilePageLayout(void*, unsigned int, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void ProfileEditor_AppendPresetTitleChoices(void*, void*, int);
extern "C" void Window_PushTextCanvas(void*, void*, int, int, int, int, int, int);
// Build this profile text page and attach it with its page-specific UI options.
// Original: arm9/ov012 @ 0x0218A574; symbol: func_ov012_0218a574; size: 0x7C.
extern "C" void Graphics_BuildIndexedProfileRecordValuesPage(unsigned char* screen) {
    Graphics_ConfigureProfilePageLayout(screen, screen[0x1371], 15, 1);
    memset(*(void**)(screen + 0x1374), 0, 0x960);
    ProfileEditor_AppendPresetTitleChoices(screen, *(void**)(screen + 0x1374), 0);

    Window_PushTextCanvas(screen + 0xac, *(void**)(screen + 0x1374), 0, 0, 1, 1, 0, 0);
}
