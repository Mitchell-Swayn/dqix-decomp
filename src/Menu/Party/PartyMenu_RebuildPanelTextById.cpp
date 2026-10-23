#include <globaldefs.h>
ARM
// Preserve the state-field snapshots and arithmetic intermediates in the original.
#pragma opt_propagation off
struct MenuTextOwner {};
typedef void (MenuTextOwner::*TextBuilder)(void*, int);
struct StateTransition { int source, destination; };
struct WindowCanvasOwner;
struct WindowCanvasRecord;
struct Owner;
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*, unsigned);
extern "C" void* memset(void*, int, unsigned);
extern "C" int Window_ReplaceCanvasTextById(Owner*, unsigned, void*, unsigned, unsigned char);
// Original data: arm9/main @ 0x020E6D5C; symbol: data_020e6d5c.
// Native ARM ABI null member-function pointer pair.
extern "C" TextBuilder ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original data: arm9/ov002 @ 0x0216D3B0; symbol: data_ov002_0216d3b0.
// Lazy initialization guards for menu text dispatch tables.
extern "C" unsigned PartyMenuRebuildPanelTextById_LazyInitializationGuardsForMenuContentBuilderDispatch[2];
// Original data: arm9/ov002 @ 0x0216CFAC; symbol: data_ov002_0216cfac.
// Native member-function pairs indexed by panel ID; unset entries use the shared null pair.
extern "C" TextBuilder PartyMenuRebuildPanelTextById_MenuStateContentBuilders[44];
// Original data: arm9/ov002 @ 0x0216CAE8 and 0x0216CAEC.
// Eight-byte source/destination state transitions, terminated by a negative source.
extern "C" StateTransition PartyMenu_RebuildPanelTextById_StateRebuildTransitionRecords[];
struct DestinationRecord { int destination, nextSource; };
extern "C" DestinationRecord PartyMenu_RebuildPanelTextById_StateRebuildTransitionRecords_Copy2[];
// Original: arm9/ov002 @ 0x0215B9A4; symbol: func_ov002_0215b9a4; size: 0x204.
// Rebuilds panel text through its native member-function table and refreshes dependent state panels.
extern "C" void PartyMenu_RebuildPanelTextById(char* self, int id, int alternate)
{
    unsigned char* canvas = (unsigned char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), id);
    if (!canvas) return;
    if (alternate) canvas[0xc5] |= 0x40;
    else canvas[0xc5] &= ~0x40;
    int textMode = 0;
    if (canvas[0xc5] & 2) textMode = 1;
    memset(*(void**)(self + 0x1bd0), 0, 0x960);
    if (!(PartyMenuRebuildPanelTextById_LazyInitializationGuardsForMenuContentBuilderDispatch[1] & 1)) {
        TextBuilder empty = ShopUpdateInterface_UnknownRoleInitializedBytes;
        PartyMenuRebuildPanelTextById_MenuStateContentBuilders[0] = empty;
        PartyMenuRebuildPanelTextById_MenuStateContentBuilders[23] = empty;
        PartyMenuRebuildPanelTextById_MenuStateContentBuilders[30] = empty;
        PartyMenuRebuildPanelTextById_MenuStateContentBuilders[36] = empty;
        PartyMenuRebuildPanelTextById_MenuStateContentBuilders[40] = empty;
        PartyMenuRebuildPanelTextById_MenuStateContentBuilders[41] = empty;
        PartyMenuRebuildPanelTextById_MenuStateContentBuilders[42] = empty;
        PartyMenuRebuildPanelTextById_MenuStateContentBuilders[43] = empty;
        PartyMenuRebuildPanelTextById_LazyInitializationGuardsForMenuContentBuilderDispatch[1] |= 1;
    }
    if (!PartyMenuRebuildPanelTextById_MenuStateContentBuilders[id]) return;
    (((MenuTextOwner*)self)->*PartyMenuRebuildPanelTextById_MenuStateContentBuilders[id])(*(void**)(self + 0x1bd0), textMode);
    Window_ReplaceCanvasTextById((Owner*)(self + 0xec8), id, *(void**)(self + 0x1bd0), 0, 0);
    if (!*(int*)(self + 0x1bcc)) return;
    register int next;
    for (register int i = 0; PartyMenu_RebuildPanelTextById_StateRebuildTransitionRecords[i].source >= 0; ++i) {
        if (*(int*)(self + 0x1bb8) == PartyMenu_RebuildPanelTextById_StateRebuildTransitionRecords[i].source) {
            next = PartyMenu_RebuildPanelTextById_StateRebuildTransitionRecords_Copy2[i].destination;
            memset(*(void**)(self + 0x1bd0), 0, 0x960);
            if (!PartyMenuRebuildPanelTextById_MenuStateContentBuilders[next]) break;
            (((MenuTextOwner*)self)->*PartyMenuRebuildPanelTextById_MenuStateContentBuilders[next])(*(void**)(self + 0x1bd0), textMode);
            Window_ReplaceCanvasTextById((Owner*)(self + 0xec8), (unsigned char)next, *(void**)(self + 0x1bd0), 0, 0);
        }
    }
    *(int*)(self + 0x1bcc) = 0;
}
