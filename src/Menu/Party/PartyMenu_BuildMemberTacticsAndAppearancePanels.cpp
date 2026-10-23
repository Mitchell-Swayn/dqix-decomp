#include <globaldefs.h>
ARM
#pragma force_active on
// Keep state snapshots and narrowing operations visible to the original compiler.
#pragma opt_propagation off
#define WORD(o) (*(int*)(self + (o)))
#define HALF(o) (*(short*)(self + (o)))
#define BYTE(o) (*(unsigned char*)(self + (o)))
#define SBYTE(o) (*(signed char*)(self + (o)))
#define POINTER(o) (*(char**)(self + (o)))
struct PartyMenuState;
struct WindowCanvasOwner;
struct WindowCanvasRecord;
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*, int, int, int);
extern "C" void* memset(void*, int, unsigned);
extern "C" void Window_PushTextCanvas(void*, void*, int, int, int, int, int, int);
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*, unsigned);
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(void*, unsigned, unsigned);
extern "C" void Window_SetCanvasDisplayAttribute(void*, int, int);
extern "C" void Window_SetCanvasEnabled(void*, int, int);
extern "C" void Window_SelectCanvasById(void*, unsigned);
struct CanvasCoordinates {
    char unknown_00[0xa8];
    short width, height, x, y;
    char unknown_b0[0x12];
    short margin;
};
extern "C" void PartyMenu_AppendSelectedMemberCommandHelp(char*, char*, int);
extern "C" void Graphics_FormatPartyMemberStatusText(char*, char*, int);
extern "C" void Text_AppendPartyMemberSelectionList(char*, char*, int);
// Original: arm9/ov002 @ 0x0215F6A4; symbol: func_ov002_0215f6a4; size: 0x214.
// Builds member help, status and selection canvases, then aligns the two lower panels beneath the selection.
extern "C" void PartyMenu_BuildMemberTacticsAndAppearancePanels(char* self)
{
    Window_BindNextCanvasResourceByFormatAndLayer(self + 0xec8, 0, 3);
    PartyMenu_ConfigurePanelLayout((PartyMenuState*)self, 27, 17, 1);
    memset(POINTER(0x1bd0), 0, 0x960);
    PartyMenu_AppendSelectedMemberCommandHelp(self, POINTER(0x1bd0), 0);
    Window_PushTextCanvas(self + 0xec8, POINTER(0x1bd0), 0, 0, 0, 0, 0, 0);
    Window_BindNextCanvasResourceByFormatAndLayer(self + 0xec8, 0, 3);
    PartyMenu_ConfigurePanelLayout((PartyMenuState*)self, 26, 1, 1);
    memset(POINTER(0x1bd0), 0, 0x960);
    Graphics_FormatPartyMemberStatusText(self, POINTER(0x1bd0), 0);
    Window_PushTextCanvas(self + 0xec8, POINTER(0x1bd0), 0, 1, 0, 1, 0, 0);
    Window_BindNextCanvasResourceByFormatAndLayer(self + 0xec8, 0, 2);
    PartyMenu_ConfigurePanelLayout((PartyMenuState*)self, WORD(0x1bb8) & 255, 1, 1);
    memset(POINTER(0x1bd0), 0, 0x960);
    Text_AppendPartyMemberSelectionList(self, POINTER(0x1bd0), 0);
    Window_PushTextCanvas(self + 0xec8, POINTER(0x1bd0), 0, 1, 0, 1, 0, 0);
    CanvasCoordinates* selected = (CanvasCoordinates*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), WORD(0x1bb8) & 255);
    if (selected) {
        short x = selected->x;
        short y = selected->y;
        short height = selected->height;
        CanvasCoordinates* canvas = (CanvasCoordinates*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), 26);
        if (canvas) {
            canvas->x = x;
            canvas->y = y + height;
            canvas->margin = 0;
        }
        canvas = (CanvasCoordinates*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), 27);
        if (canvas) {
            canvas->x = 17;
            canvas->y = y + height;
            canvas->margin = 0;
        }
    }
}
