#include <globaldefs.h>
extern "C" int Ov002_InitializeCurrentAndResourceRecords(char*);
extern "C" void PartyMenu_OpenGoldPanel(void*);
extern "C" void PartyMenu_OpenBagIndicatorPanel(char*);
extern "C" void PartyMenu_ConfigureSelectionForCurrentScreen(void*);
extern "C" void PartyMenu_OpenRootCommandPanel(char*);
extern "C" void PartyMenu_BuildMiscellaneousMenuAndHelp(char*);
// Original: arm9/ov002 @ 0x0215A938; symbol: func_ov002_0215a938; size: 0x7C.
// Initializes overlay selection records and refreshes the available resource panels.
extern "C" void PartyMenu_RebuildRootPanels(char* self) {
    if (!Ov002_InitializeCurrentAndResourceRecords(self)) return;
    *(unsigned*)(self + 0x1bb8) = 1;
    PartyMenu_OpenGoldPanel(self);
    PartyMenu_OpenBagIndicatorPanel(self);
    PartyMenu_ConfigureSelectionForCurrentScreen(self);
    PartyMenu_OpenRootCommandPanel(self);
    if (*(short*)(self + 0x1be0) == 5) {
        *(unsigned*)(self + 0x1bb8) = 0x15;
        PartyMenu_ConfigureSelectionForCurrentScreen(self);
        PartyMenu_BuildMiscellaneousMenuAndHelp(self);
    }
    *(unsigned*)(self + 0x1bc0) = 1;
}
