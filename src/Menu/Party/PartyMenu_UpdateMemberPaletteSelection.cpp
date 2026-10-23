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
extern "C" int TestSelectedRecordReadyAndByteFlagBitOne(void*, int);
extern "C" void PartyMenu_ConfigureSelectionForCurrentScreen(void*);
extern "C" int PartyMenu_IsCancelRequested(void*, int);
extern "C" void PartyMenu_PopPanelGroupAndRestoreSelection(void*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(void*, int, void*);
// Original data: arm9/main @ 0x02114E30; symbol: data_02114e30. Input repeater state.
extern "C" char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02108760; symbol: data_02108760. Shared sound state.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" char* GameObject_GetLinkedIndexedState(void*);
extern "C" void PartyMenu_LoadSelectedPaletteSwatch(void*);
extern "C" void Graphics_RefreshTwoBoundTextRecordsAndClearAttribute(void*);
extern "C" void PartyMenu_RebuildPanelTextById(void*, unsigned, unsigned);
extern "C" void* GameResources_GetInstance();
extern "C" void Field_QueuePartyMemberEquipmentRefresh(void*, int, int, int, int);
extern "C" void Graphics_UpdatePartyMemberPaletteColor();
extern "C" void Graphics_LoadPartyPalettePreset(int, int);
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void*);
extern "C" void Ov017_ProcessIndexedSignedEntries();
// Original: arm9/ov002 @ 0x0216806C; symbol: func_ov002_0216806c; size: 0x254.
// Previews palette changes, commits the chosen member palette and refreshes graphics and equipment when required.
extern "C" void PartyMenu_UpdateMemberPaletteSelection(char* self)
{
    if (WORD(0x1bc0) == 0) {
        PartyMenu_ConfigureSelectionForCurrentScreen(self);
        Graphics_RefreshTwoBoundTextRecordsAndClearAttribute(self);
        PartyMenu_ConfigureSelectionForCurrentScreen(self);
        PartyMenu_LoadSelectedPaletteSwatch(self);
        ++WORD(0x1bc0);
        return;
    }
    if (WORD(0x1bc0) != 1) return;
    short previous = HALF(0x1c06);
    HALF(0x1c06) = Selection_ReadEnabledIndexFromControl(self + 0xec8);
    if (previous != HALF(0x1c06)) {
        PartyMenu_LoadSelectedPaletteSwatch(self);
        PartyMenu_RebuildPanelTextById(self, 29, 0);
    }
    int confirm = Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x601);
    int pressed = (confirm | TestSelectedRecordReadyAndByteFlagBitOne(self + 0xec8, 20)) != 0;
    if (pressed) {
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
        int memberIndex = SBYTE(0x1c20);
        char* member = _ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(), memberIndex);
        if (!member) return;
        char* record = GameObject_GetLinkedIndexedState(member);
        if ((unsigned char)record[0x56a] != HALF(0x1c06) && *(short*)(record + 0x488) < 0) {
            *(short*)(member + 2) = -1;
            Field_QueuePartyMemberEquipmentRefresh(GameResources_GetInstance(), memberIndex, 0, 0, 0);
        }
        record[0x56a] = HALF(0x1c06);
        Graphics_UpdatePartyMemberPaletteColor();
        Graphics_LoadPartyPalettePreset(1, -1);
        Graphics_LoadPartyPalettePreset(8, -1);
        Graphics_LoadPartyPalettePreset(6, -1);
        Graphics_LoadPartyPalettePreset(7, -1);
        void* network = Network_GetConnectionManager();
        if (network && Network_IsSessionActive(network)) Ov017_ProcessIndexedSignedEntries();
        PartyMenu_PopPanelGroupAndRestoreSelection(self);
        PartyMenu_PopPanelGroupAndRestoreSelection(self);
        Window_SetCanvasDisplayAttribute(self + 0xec8, 24, 0);
        Window_SetCanvasDisplayAttribute(self + 0xec8, 26, 0);
        Window_SetCanvasDisplayAttribute(self + 0xec8, 27, 0);
        return;
    }
    if (PartyMenu_IsCancelRequested(self, 1)) {
        PartyMenu_PopPanelGroupAndRestoreSelection(self);
        PartyMenu_PopPanelGroupAndRestoreSelection(self);
        Window_SetCanvasDisplayAttribute(self + 0xec8, 24, 0);
        Window_SetCanvasDisplayAttribute(self + 0xec8, 26, 0);
        Window_SetCanvasDisplayAttribute(self + 0xec8, 27, 0);
    }
}
