#include <globaldefs.h>
ARM
struct WindowCanvasOwner;
struct WindowCanvasRecord;
extern "C" WindowCanvasRecord* Window_GetTopTextCanvas(WindowCanvasOwner*);
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*, unsigned);
extern "C" void Window_PopCanvasesAndResetSelection(void*, int);
extern "C" void Window_SetCanvasDisplayAttribute(char*, int, int);
extern "C" void PartyMenu_ConfigureSelectionForCurrentScreen(char*);
extern "C" void PartyMenu_RebuildPanelTextById(char*, int, int);
// Original data: arm9/ov002 @ 0x0216C99D and 0x0216C99E; original symbols: data_ov002_0216c99d, data_ov002_0216c99e.
// Interleaved panel IDs and the related canvas IDs restored after a panel-group pop.
extern "C" unsigned char PartyMenuPopPanelGroupAndRestoreSelection_UnknownRoleInitializedBytes[];
extern "C" unsigned char PartyMenuPopPanelGroupAndRestoreSelection_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/ov002 @ 0x02156E90; symbol: func_ov002_02156e90; size: 0x160.
// Pops a related panel group, restores its parent selection and rebuilds the parent text.
extern "C" void PartyMenu_PopPanelGroupAndRestoreSelection(char* self)
{
    int count = 1;
    char* top = (char*)Window_GetTopTextCanvas((WindowCanvasOwner*)(self + 0xec8));
    if (top) {
        for (int i = 0; i < 8; ++i) {
            unsigned char id = top[0xc4];
            unsigned char panelId = PartyMenuPopPanelGroupAndRestoreSelection_UnknownRoleInitializedBytes[i * 2];
            if (panelId == id) {
                count = 2;
                break;
            }
            if (id >= 44 && id <= 47) {
                count = 0;
                for (unsigned char panel = 44; panel <= 47; ++panel) {
                    if (Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), panel)) ++count;
                }
                break;
            }
        }
    }
    for (int i = 0; i < count; ++i) Window_PopCanvasesAndResetSelection(self + 0xec8, 0);
    top = (char*)Window_GetTopTextCanvas((WindowCanvasOwner*)(self + 0xec8));
    if (!top) return;
    *(int*)(self + 0x1bb8) = (unsigned char)top[0xc4];
    PartyMenu_ConfigureSelectionForCurrentScreen(self);
    for (int i = 0; i < 8; ++i) {
        unsigned char id = PartyMenuPopPanelGroupAndRestoreSelection_UnknownRoleInitializedBytes[i * 2];
        if (id == (unsigned char)top[0xc4]) {
            unsigned char id = PartyMenuPopPanelGroupAndRestoreSelection_UnknownRoleInitializedBytes_Variant2[i * 2];
            Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), id);
            Window_SetCanvasDisplayAttribute(self + 0xec8, id, 0);
            break;
        }
    }
    PartyMenu_RebuildPanelTextById(self, *(int*)(self + 0x1bb8) & 255, 0);
}
