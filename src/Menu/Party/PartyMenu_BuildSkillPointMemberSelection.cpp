#include <globaldefs.h>
ARM
#pragma force_active on
// Keep state snapshots and narrowing operations visible to the original compiler.
#pragma opt_propagation off
#pragma opt_common_subs off
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
#include <GameState/GameState.h>
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*, int);
extern "C" void PartyMenu_CopySelectableMemberIndices(char*, int*);
extern "C" void PartyMenu_FormatSelectedMemberSkillPoints(char*, char*, int);
extern "C" void PartyMenu_AppendSkillPointMemberNames(char*, char*, int);
extern "C" void PartyMenu_RebuildPanelTextById(void*, unsigned, unsigned);
// Original data: arm9/ov002 @ 0x0216C9F9; symbol: data_ov002_0216c9f9.
// Two panel IDs whose horizontal positions follow panel 21's right edge.
extern "C" unsigned char PartyMenuBuildSkillPointMemberSelection_UnknownRoleInitializedBytes[];
// Original: arm9/ov002 @ 0x02160274; symbol: func_ov002_02160274; size: 0x228.
// Counts available members to size the skill-point panel, builds its member list and aligns dependent panels.
extern "C" void PartyMenu_BuildSkillPointMemberSelection(char* self)
{
    int indices[4];
    GameState* state = GameState::GetInstance();
    PartyMenu_CopySelectableMemberIndices(self, indices);
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        int valid;
        int index = indices[i];
        if (index >= 0 && index <= 3) valid = 1;
        else valid = 0;
        if (valid && GameState_GetObjectWithFlag100(state, index)) ++count;
    }
    int rows = count * 2;
    if (count == 1) ++rows;
    PartyMenu_ConfigurePanelLayout((PartyMenuState*)self, 32, 16, (short)(rows + 10));
    memset(POINTER(0x1bd0), 0, 0x960);
    PartyMenu_FormatSelectedMemberSkillPoints(self, POINTER(0x1bd0), 0);
    Window_PushTextCanvas(self + 0xec8, POINTER(0x1bd0), 0, 0, 0, 1, 0, 0);
    Window_BindNextCanvasResourceByFormatAndLayer(self + 0xec8, 0, 2);
    PartyMenu_ConfigurePanelLayout((PartyMenuState*)self, WORD(0x1bb8) & 255, 16, 8);
    memset(POINTER(0x1bd0), 0, 0x960);
    PartyMenu_AppendSkillPointMemberNames(self, POINTER(0x1bd0), 0);
    Window_PushTextCanvas(self + 0xec8, POINTER(0x1bd0), 0, 1, 0, 1, 0, 0);
    Window_SetCanvasDisplayAttribute(self + 0xec8, 32, 0);
    Window_SetCanvasEnabled(self + 0xec8, 0, 41);
    CanvasCoordinates* canvas = (CanvasCoordinates*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), 21);
    if (canvas) {
        register int right = canvas->x + canvas->width;
        for (int i = 0; i < 2; ++i) {
            canvas = (CanvasCoordinates*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), PartyMenuBuildSkillPointMemberSelection_UnknownRoleInitializedBytes[i]);
            if (canvas) {
                short y = canvas->y;
                canvas->x = (short)right;
                canvas->y = y;
            }
        }
    }
    PartyMenu_RebuildPanelTextById(self, WORD(0x1bb8) & 255, 0);
}
