#include <globaldefs.h>
extern "C" void PartyMenu_RebuildPanelTextById(void*, unsigned, unsigned);
// Original: arm9/ov002 @ 0x0215B6C0; symbol: func_ov002_0215b6c0; size: 0x60.
extern "C" ARM void Ov002_InitializeSelectionFlags(void* object) {
    *(unsigned*)((char*)object + 0x1bcc) = 1;
    PartyMenu_RebuildPanelTextById(object, 0x10, 1);
    PartyMenu_RebuildPanelTextById(object, 0x13, 0);
    PartyMenu_RebuildPanelTextById(object, 7, 1);
    PartyMenu_RebuildPanelTextById(object, 8, 0);
    PartyMenu_RebuildPanelTextById(object, 4, 1);
}
