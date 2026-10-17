#include <globaldefs.h>
extern "C" void Graphics_ConfigureProfilePageLayout(void*, unsigned int, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void Text_AppendProfileRecordFragments(void*, void*, int);
extern "C" void func_0205d304(void*, void*, int, int, int, int, int, int);
// Build a profile-screen text page in its shared buffer, then attach it to the UI.
// Original: arm9/ov012 @ 0x021898BC; symbol: func_ov012_021898bc; size: 0x78.
extern "C" void func_ov012_021898bc(unsigned char* screen) {
    Graphics_ConfigureProfilePageLayout(screen, screen[0x1371], 20, 1);
    memset(*(void**)(screen + 0x1374), 0, 0x960);
    Text_AppendProfileRecordFragments(screen, *(void**)(screen + 0x1374), 0);
    func_0205d304(screen + 0xac, *(void**)(screen + 0x1374), 0, 1, 0, 1, 0, 0);
}
