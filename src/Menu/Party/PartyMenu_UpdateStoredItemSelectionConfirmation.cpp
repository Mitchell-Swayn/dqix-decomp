#include <globaldefs.h>
ARM
#pragma force_active on
// Preserve stored cursor narrowing and independent state reloads.
#pragma opt_propagation off
#pragma opt_common_subs off
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
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" void PartyMenu_BuildItemSelectionConfirmation(void*);
extern "C" void* ZoneState2754_FindPrimaryRecordByKey(void*, int);
extern "C" void PartyMenu_RemoveSelectedInventoryItem(char*, int, int, int, unsigned char);
// Original: arm9/ov002 @ 0x0216BD34; symbol: func_ov002_0216bd34; size: 0x2a0.
// Confirms a stored-item selection, records its owner and slot, optionally removes it, and clears unhandled selections.
extern "C" void PartyMenu_UpdateStoredItemSelectionConfirmation(char* self)
{
    char* state = _ZN9GameState11GetInstanceEv();
    if (WORD(0x1bc0) == 0) {
        HALF(0x1c14) = 0;
        Window_BindNextCanvasResourceByFormatAndLayer(self + 0xec8, 0, 2);
        PartyMenu_ConfigureSelectionForCurrentScreen(self);
        PartyMenu_BuildItemSelectionConfirmation(self);
        BYTE(0x1c20) = *(int*)(self + 0x1c3c + HALF(0x1be6) * 4);
        if (SBYTE(0x1c20) < 0) BYTE(0x1c20) = 4;
        ++WORD(0x1bc0);
        return;
    }
    if (WORD(0x1bc0) != 1) return;
    WORD(0x247c) |= 4;
    HALF(0x1c14) = Selection_ReadEnabledIndexFromControl(self + 0xec8);
    signed char owner = SBYTE(0x1c20);
    int key = HALF(0x1c22);
    int handled = 0;
    int input = Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x601);
    int confirm = (input | TestSelectedRecordReadyAndByteFlagBitOne(self + 0xec8, 20)) != 0;
    if (confirm) {
        BYTE(0xf80) = WORD(0x1bb8);
        WORD(0x247c) &= ~4;
        switch (HALF(0x1c14)) {
        case 0:
            SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
            BYTE(0x2487) = 1;
            if (ZoneState2754_FindPrimaryRecordByKey(self + 0x7ec, (short)key)) {
                *(unsigned short*)(state + 0x71dc) = (unsigned short)key;
                *(unsigned short*)(state + 0x7f58) = (unsigned short)key;
                if (key > 0) {
                    *(short*)(state + 0x71de) = owner;
                    if (owner >= 0) {
                        *(short*)(state + 0x71e0) = HALF(0x1be8);
                        int slot = HALF(0x1be8);
                        if (slot < 0) break;
                        if (BYTE(0x2486)) {
                            if (owner >= 0 && owner <= 3)
                                PartyMenu_RemoveSelectedInventoryItem(self, owner, (short)key, slot, 0);
                            else
                                PartyMenu_RemoveSelectedInventoryItem(self, 4, (short)key, slot, 0);
                        }
                        handled = 1;
                    } else break;
                }
            }
            break;
        case 1:
            SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
            HALF(0x1c14) = -1;
            PartyMenu_PopPanelGroupAndRestoreSelection(self);
            handled = 1;
            break;
        }
    } else if (PartyMenu_IsCancelRequested(self, 1)) {
        HALF(0x1c14) = 0;
        handled = 1;
        PartyMenu_PopPanelGroupAndRestoreSelection(self);
    }
    if (!handled) {
        state = _ZN9GameState11GetInstanceEv();
        *(short*)(state + 0x71dc) = 0;
        *(short*)(state + 0x7f58) = 0;
        *(short*)(state + 0x71de) = -1;
        *(short*)(state + 0x71e0) = -1;
    }
}
