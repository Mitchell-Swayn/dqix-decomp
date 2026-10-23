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
extern "C" int TestSelectedRecordReadyAndByteFlagBitOne(void*, int);
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
struct WindowCanvasOwner;
struct CanvasCoordinates {
    char unknown_00[0xa8];
    short width, height, x, y;
};
extern "C" CanvasCoordinates* Window_FindActiveCanvasById(WindowCanvasOwner*, unsigned);
extern "C" int Graphics_GetIndexedPartyAndExtraTextValue(void*, int);
extern "C" void PartyMenu_RebuildPanelTextById(void*, unsigned, int);
extern "C" void RebuildPartyOptionTextAndSelectMode11(void*);
// Original: arm9/ov002 @ 0x021644A8; symbol: func_ov002_021644a8; size: 0x29c.
// Selects a bulk-inventory owner, updates its adjacent canvas, and enters confirmation or restores the category panel.
extern "C" void PartyMenu_UpdateBulkInventoryOwnerSelection(char* self)
{
    if (WORD(0x1bc0) == 0) {
        HALF(0x1bf0) = 0;
        Window_BindNextCanvasResourceByFormatAndLayer(self + 0xec8, 0, 2);
        PartyMenu_ConfigureSelectionForCurrentScreen(self);
        RebuildPartyOptionTextAndSelectMode11(self);
        ++WORD(0x1bc0);
        return;
    }
    if (WORD(0x1bc0) != 1) return;
    WORD(0x247c) |= 4;
    short previous = HALF(0x1bf0);
    HALF(0x1bf0) = Selection_ReadEnabledIndexFromControl(self + 0xec8);
    BYTE(0x1c20) = Graphics_GetIndexedPartyAndExtraTextValue(self, HALF(0x1bf0));
    signed char owner = SBYTE(0x1c20);
    BYTE(0x1c21) = owner;
    Window_SetCanvasDisplayAttribute(self + 0xec8, 13, 1);
    if (HALF(0x1bf0) != 0) {
        PartyMenu_RebuildPanelTextById(self, 13, 0);
        Window_SetCanvasEnabled(self + 0xec8, 1, 13);
        CanvasCoordinates* from = Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), 11);
        CanvasCoordinates* to = Window_FindActiveCanvasById((WindowCanvasOwner*)(self + 0xec8), 13);
        if (from && to) {
            to->x = from->x + from->width;
            to->y = 1;
        }
    } else {
        Window_SetCanvasEnabled(self + 0xec8, 0, 13);
    }
    if (previous != HALF(0x1bf0)) return;
    int input = Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x601);
    int confirm = (input | TestSelectedRecordReadyAndByteFlagBitOne(self + 0xec8, 20)) != 0;
    if (confirm) {
        BYTE(0x1c32) = 0;
        BYTE(0xf80) = WORD(0x1bb8);
        WORD(0x247c) &= ~4;
        Window_SetCanvasDisplayAttribute(self + 0xec8, 11, 1);
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
        HALF(0x1c12) = 0;
        HALF(0x1c28) = 0x238d;
        HALF(0x1c2a) = -1;
        WORD(0x1bb8) = 38;
        WORD(0x1bbc) = 11;
        WORD(0x1bc0) = 0;
        BYTE(0x1c2e) = 1;
        return;
    }
    if (PartyMenu_IsCancelRequested(self, 1)) {
        PartyMenu_PopPanelGroupAndRestoreSelection(self);
        signed char invalid = -1;
        HALF(0x1bf0) = invalid;
        SBYTE(0x1c20) = invalid;
        SBYTE(0x1c21) = invalid;
        Window_SelectCanvasById(self + 0xec8, WORD(0x1bb8) = 4);
        PartyMenu_RebuildPanelTextById(self, WORD(0x1bb8) & 255, 0);
        PartyMenu_ConfigureSelectionForCurrentScreen(self);
    }
}
