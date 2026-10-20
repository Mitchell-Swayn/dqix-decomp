struct PartyMenuState;
#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" void Text_AppendSixResourceOptions(char*, char*, int);
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);
extern "C" void Window_PushTextCanvas(void*, void*, int, int, int, int, int, int);
// Original: arm9/ov002 @ 0x0215C0F8; symbol: func_ov002_0215c0f8; size: 0x80.
// Builds the two text buffers and configures the resource-selection menu.
extern "C" void PartyMenu_OpenRootCommandPanel(char* self) {
    PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self), *(int*)(self + 0x1bb8) & 0xff, 1, 1);
    memset(*(void**)(self + 0x1bd0), 0, 0x960);
    Text_AppendSixResourceOptions(self, *(char**)(self + 0x1bd0), 0);
    Window_PushTextCanvas(self + 0xec8, *(void**)(self + 0x1bd0), 0, 1, 0, 1, 0, 0);
}
