struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
// Original data: arm9/ov002 @ 0x216c984; symbol: data_ov002_0216c984.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 040e101f181a.
// Observed span: 6 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" unsigned char PartyMenuRefreshStatusDependentPanels_UnknownRoleInitializedBytes[];
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void PartyMenu_RebuildPanelTextById(void*, unsigned, unsigned);
// Original: arm9/ov002 @ 0x0215B648; symbol: func_ov002_0215b648; size: 0x78.
extern "C" ARM void PartyMenu_RefreshStatusDependentPanels(void* owner) {
    unsigned char* p = (unsigned char*)owner;
    if (!p[0x1cc4]) return;
    for (int i = 0; i < 6; ++i) {
        unsigned char id = PartyMenuRefreshStatusDependentPanels_UnknownRoleInitializedBytes[i];
        void* record = (void*)Window_FindActiveCanvasById((WindowCanvasOwner*)(p + 0xec8), id);
        if (record) {
            unsigned flag = *(unsigned short*)((char*)record + 0xc2) != 0;
            PartyMenu_RebuildPanelTextById(owner, id, flag);
        }
    }
}
