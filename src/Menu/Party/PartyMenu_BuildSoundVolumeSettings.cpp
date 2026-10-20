struct PartyMenuState;
#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma force_active on
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);
extern "C" void Window_PushTextCanvas(void*, void*, int, int, int, int, int, int);
extern "C" void PartyMenu_AppendSoundVolumeSettings(void*, void*, int);
// Original: arm9/ov002 @ 0x02160C68; symbol: func_ov002_02160c68; size: 0x80.
// Builds the sound volume text in the menu buffer and opens its panel.
extern "C" void PartyMenu_BuildSoundVolumeSettings(char* self) {
    PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self), *(int*)(self + 0x1bb8) & 0xff, 1, 14);
    memset(*(void**)(self + 0x1bd0), 0, 0x960);
    PartyMenu_AppendSoundVolumeSettings(self, *(char**)(self + 0x1bd0), 0);
    Window_PushTextCanvas(self + 0xec8, *(void**)(self + 0x1bd0), 0, 0, 0, 0, 0, 0);
}
