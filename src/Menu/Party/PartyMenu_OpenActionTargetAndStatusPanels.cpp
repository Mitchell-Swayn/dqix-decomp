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
extern "C" void PartyMenu_AppendActionTargetNames(char*, char*, int);
extern "C" void PartyMenu_FormatActionTargetStatus(char*, char*, int);
struct Owner;
extern "C" int Window_ReplaceCanvasTextById(Owner*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov002 @ 0x0215CE94; symbol: func_ov002_0215ce94; size: 0x254.
// Opens target names and status canvases, placing the status beside or below the preceding target selection.
extern "C" void PartyMenu_OpenActionTargetAndStatusPanels(char* self)
{
    short x = 22;
    short y = 1;
    if (HALF(0x1c26) != -1) {
        CanvasCoordinates* previous = (CanvasCoordinates*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), 16);
        if (previous) { x = 1; y = previous->y + previous->height; }
    }
    PartyMenu_ConfigurePanelLayout((PartyMenuState*)self, WORD(0x1bb8) & 255, x, y);
    memset(POINTER(0x1bd0), 0, 0x960);
    PartyMenu_AppendActionTargetNames(self, POINTER(0x1bd0), 0);
    Window_PushTextCanvas(self + 0xec8, POINTER(0x1bd0), 0, 1, 0, 1, 0, 0);
    CanvasCoordinates* canvas = (CanvasCoordinates*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), WORD(0x1bb8) & 255);
    if (HALF(0x1c26) != -1) canvas = (CanvasCoordinates*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), 17);
    if (canvas) {
        Window_BindNextCanvasResourceByFormatAndLayer(self + 0xec8, 0, 3);
        PartyMenu_ConfigurePanelLayout((PartyMenuState*)self, 8, canvas->x, (short)(canvas->y + canvas->height));
        memset(POINTER(0x1bd0), 0, 0x960);
        PartyMenu_FormatActionTargetStatus(self, POINTER(0x1bd0), 0);
        Window_PushTextCanvas(self + 0xec8, POINTER(0x1bd0), 0, 0, 0, 1, 0, 0);
        CanvasCoordinates* status = (CanvasCoordinates*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), 8);
        if (status) {
            short x = status->x;
            short y = status->y;
            short width = status->width;
            if (HALF(0x1c26) != -1) y -= 4;
            else x = 31 - width;
            status->x = x;
            status->y = y;
            Window_ReplaceCanvasTextById((Owner*)(self + 0xec8), 8, POINTER(0x1bd0), 1, 0);
        }
    }
    Window_SelectCanvasById(self + 0xec8, WORD(0x1bb8) & 255);
    Window_SetCanvasDisplayAttribute(self + 0xec8, WORD(0x1bb8) & 255, 0);
}
