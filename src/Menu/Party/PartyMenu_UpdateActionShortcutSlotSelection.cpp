#include <globaldefs.h>
ARM
#pragma force_active on
// Preserve stored cursor narrowing and independent state reloads.
#pragma opt_propagation off
#define WORD(o) (*(int*)(self + (o)))
#define HALF(o) (*(short*)(self + (o)))
#define BYTE(o) (*(unsigned char*)(self + (o)))
#define SBYTE(o) (*(signed char*)(self + (o)))
#define POINTER(o) (*(char**)(self + (o)))
extern "C" int Input_IsKeyMaskNewlyPressed(void*, unsigned);
extern "C" int Selection_ReadEnabledIndexFromControl(void*);
extern "C" int TestSelectedRecordReadyAndByteFlagBitOne(char*,int);
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(void*, unsigned, unsigned);
extern "C" void Window_SetCanvasDisplayAttribute(void*, int, int);
extern "C" void Window_SetCanvasEnabled(void*, int, int);
extern "C" void Window_SelectCanvasById(void*, unsigned);
extern "C" void PartyMenu_ConfigureSelectionForCurrentScreen(void*);
extern "C" int PartyMenu_IsCancelRequested(void*, int);
extern "C" void PartyMenu_PopPanelGroupAndRestoreSelection(void*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(void*, int, void*);
// Original data: arm9/main @ 0x02114E30; symbol: data_02114e30. Input repeater state.
extern "C" char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02108760; symbol: data_02108760. Shared sound state.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
extern "C" void Ov002_CopySevenIndexedStateBytes(void*);
extern "C" void GameState_CopySevenIndexedBytes(void*);
extern "C" void RebuildSevenMappedMenuOptions(void*);
extern "C" void PartyMenu_BuildMiscellaneousMenuAndHelp(void*);
// Original: arm9/ov002 @ 0x021696C0; symbol: func_ov002_021696c0; size: 0x28c.
// Updates the seven action-shortcut slots and the save, select-action and cancel transitions.
extern "C" void PartyMenu_UpdateActionShortcutSlotSelection(char* self)
{
    if (WORD(0x1bc0) == 0) {
        WORD(0x247c) &= ~4;
        Window_SetCanvasEnabled(self + 0xec8, 0, 1);
        Window_SetCanvasEnabled(self + 0xec8, 0, 41);
        PartyMenu_PopPanelGroupAndRestoreSelection(self);
        WORD(0x1bb8) = 33;
        WORD(0x1bc0) = 50;
        return;
    }
    if (WORD(0x1bc0) == 50) {
        GameState_CopySevenIndexedBytes(self);
        HALF(0x1c0a) = 0;
        Window_BindNextCanvasResourceByFormatAndLayer(self + 0xec8, 0, 2);
        PartyMenu_ConfigureSelectionForCurrentScreen(self);
        RebuildSevenMappedMenuOptions(self);
        WORD(0x1bc0) = 1;
        return;
    }
    if (WORD(0x1bc0) == 1) {
        WORD(0x247c) |= 4;
        HALF(0x1c0a) = Selection_ReadEnabledIndexFromControl(self + 0xec8);
        int input = Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x601);
        int confirm = (input | TestSelectedRecordReadyAndByteFlagBitOne(self + 0xec8, 20)) != 0;
        if (confirm && HALF(0x1c0a) == 7) {
            Ov002_CopySevenIndexedStateBytes(self);
            SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
            WORD(0x247c) &= ~4;
            PartyMenu_PopPanelGroupAndRestoreSelection(self);
            WORD(0x1bb8) = 33;
            WORD(0x1bc0) = 100;
            return;
        }
        input = Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x601);
        confirm = (input | TestSelectedRecordReadyAndByteFlagBitOne(self + 0xec8, 20)) != 0;
        if (confirm) {
            BYTE(0xf80) = WORD(0x1bb8);
            WORD(0x247c) &= ~4;
            SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
            WORD(0x1bb8) = 34;
            WORD(0x1bc0) = 0;
            return;
        }
        if (PartyMenu_IsCancelRequested(self, 1)) {
            Ov002_CopySevenIndexedStateBytes(self);
            WORD(0x247c) &= ~4;
            PartyMenu_PopPanelGroupAndRestoreSelection(self);
            WORD(0x1bb8) = 33;
            WORD(0x1bc0) = 100;
        }
        return;
    }
    if (WORD(0x1bc0) == 100) {
        HALF(0x1c0a) = 0;
        WORD(0x1bb8) = 21;
        Window_BindNextCanvasResourceByFormatAndLayer(self + 0xec8, 0, 2);
        PartyMenu_ConfigureSelectionForCurrentScreen(self);
        PartyMenu_BuildMiscellaneousMenuAndHelp(self);
        WORD(0x1bc0) = 1;
    }
}
