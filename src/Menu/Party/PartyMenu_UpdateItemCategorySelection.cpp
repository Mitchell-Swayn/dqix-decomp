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
extern "C" int Input_IsKeyMaskNewlyPressed(void*, unsigned);
extern "C" int Selection_ReadEnabledIndexFromControl(void*);
extern "C" int TestSelectedRecordReadyAndByteFlagBitOne(char*,int);
extern "C" void PartyMenu_ConfigureSelectionForCurrentScreen(void*);
extern "C" int PartyMenu_IsCancelRequested(void*, int);
extern "C" void PartyMenu_PopPanelGroupAndRestoreSelection(void*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(void*, int, void*);
// Original data: arm9/main @ 0x02114E30; symbol: data_02114e30. Input repeater state.
extern "C" char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02108760; symbol: data_02108760. Shared sound state.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadPResources(void*);
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" char* GameObject_GetLinkedIndexedState(void*);
extern "C" void PartyMenu_OpenInventoryCategoryPanel(void*);
extern "C" int GameState_CountRecordsForCategory(void*, int);
extern "C" int Script_ReadGlobalExecutionValue();
extern "C" void TimedMessageQueue_CancelAndClear();
extern "C" void SceneMenu_QueueTreasureMapScreen(void*);
// Original: arm9/ov002 @ 0x02162714; symbol: func_ov002_02162714; size: 0x250.
// Updates item-category input, persists the chosen category and opens the inventory or treasure-map flow.
extern "C" void PartyMenu_UpdateItemCategorySelection(char* self)
{
    if (WORD(0x1bc0) == 0) {
        HALF(0x1be4) = 0;
        Window_BindNextCanvasResourceByFormatAndLayer(self + 0xec8, 0, 2);
        PartyMenu_ConfigureSelectionForCurrentScreen(self);
        PartyMenu_OpenInventoryCategoryPanel(self);
        ++WORD(0x1bc0);
        return;
    }
    if (WORD(0x1bc0) != 1) return;
    WORD(0x247c) |= 4;
    short previous = HALF(0x1be4);
    HALF(0x1be4) = Selection_ReadEnabledIndexFromControl(self + 0xec8);
    if (previous != HALF(0x1be4)) return;
    int confirm = Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x601);
    int pressed = (confirm | TestSelectedRecordReadyAndByteFlagBitOne(self + 0xec8, 20)) != 0;
    if (pressed) {
        if (WORD(0x247c) & 2) return;
        if (!(WORD(0x247c) & 16)) return;
        char* state = _ZN9GameState11GetInstanceEv();
        GameState_ReadPResources(state);
        char* protagonist = (char*)_ZN9GameState14GetProtagonistEv(state);
        if (protagonist) {
            char* record = GameObject_GetLinkedIndexedState(protagonist);
            *(short*)(record + 0x95a) = HALF(0x1be4);
        }
        switch (HALF(0x1be4)) {
        case 0:
            SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
            WORD(0x1bb8) = 4;
            WORD(0x1bc0) = 0;
            return;
        case 1:
            BYTE(0xf80) = WORD(0x1bb8);
            WORD(0x247c) &= ~4;
            SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
            BYTE(0x1c20) = 5;
            WORD(0x1bb8) = 10;
            WORD(0x1bc0) = 0;
            if (GameState_CountRecordsForCategory(self, SBYTE(0x1c20))) return;
            Script_ReadGlobalExecutionValue();
            TimedMessageQueue_CancelAndClear();
            HALF(0x1c28) = 0x2395;
            HALF(0x1c2a) = -1;
            WORD(0x1bb8) = 38;
            WORD(0x1bbc) = 3;
            return;
        case 2:
            SceneMenu_QueueTreasureMapScreen(self);
            WORD(0x1bb8) = 43;
            WORD(0x1bc0) = 0;
            return;
        }
        return;
    }
    if (PartyMenu_IsCancelRequested(self, 1)) {
        HALF(0x1be4) = -1;
        PartyMenu_PopPanelGroupAndRestoreSelection(self);
    }
}
