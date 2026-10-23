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
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadPResources(void*);
extern "C" int GameState_ReadProtagonistObjectIndex(void*);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_SetFlags(void*, unsigned);
extern "C" void Graphics_LoadPartyPalettePreset(int, int);
extern "C" void PartyMenu_BuildPartySummaryPanels(void*);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*, int, int);
extern "C" int _Z31IsSubBrightnessTransitionActiveP13GameResources(void*);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void Graphics_InitializeSecondaryDisplayResourceContext(void*, int);
extern "C" void Resource_InitializeAllocatorSet(void*, unsigned);
extern "C" int Menu_AdvanceSecondaryPanelResourceInitialization(void*);
extern "C" void Graphics_LoadIndexedSubBG1Screen(void*, int);
extern "C" void Menu_DispatchSecondaryPanelCharacterView(void*, int, int);
extern "C" void RestoreSubGraphicsBanksAndDestroyAllocators(void*);
extern "C" void GameState_EnableGlobalFlag64();
extern "C" void ComputeGrottoAndContextDependentStateFlags(int);
extern "C" int CountEligiblePartyEntriesAfterExclusions();
// Original data: arm9/ov002 @ 0x0216CC88; symbol: data_ov002_0216cc88. Three hidden canvas IDs.
extern "C" unsigned char PartyMenuUpdatePartySummaryDisplay_UnknownRoleInitializedBytes[];
// Original data: arm9/main @ 0x02114E54; symbol: data_02114e54. Shared input state.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original: arm9/ov002 @ 0x021650D4; symbol: func_ov002_021650d4; size: 0x2a4.
// Advances party-summary display initialization, brightness transitions, input and restoration of secondary graphics resources.
extern "C" void PartyMenu_UpdatePartySummaryDisplay(char* self)
{
    char* state = _ZN9GameState11GetInstanceEv();
    void* resources = GameState_ReadPResources(state);
    if (BYTE(0x1cc3) == 0) {
        if (WORD(0x1bc0) == 0) {
            SystemState_SetFlags(SystemState_GetGlobalFlags(), 1);
            Graphics_LoadPartyPalettePreset(1, -1);
            Window_BindNextCanvasResourceByFormatAndLayer(self + 0xec8, 0, 3);
            PartyMenu_ConfigureSelectionForCurrentScreen(self);
            PartyMenu_BuildPartySummaryPanels(self);
            for (int i = 0; i < 3; ++i)
                Window_SetCanvasEnabled(self + 0xec8, 0, PartyMenuUpdatePartySummaryDisplay_UnknownRoleInitializedBytes[i]);
            _Z16SetSubBrightnessP13GameResourcesii(resources, -16, 15);
            BYTE(0x1cc3) = 1;
            _ZN13SafeAllocator5ResetEv(self + 0x864);
            Graphics_InitializeSecondaryDisplayResourceContext(self + 0x8b4, 0);
            Resource_InitializeAllocatorSet(self + 0x8b4, (unsigned)(self + 0x864));
            ++WORD(0x1bc0);
            return;
        }
        if (WORD(0x1bc0) == 6) {
            ++WORD(0x1bc0);
            return;
        }
        if (WORD(0x1bc0) == 7) {
            PartyMenu_PopPanelGroupAndRestoreSelection(self);
            PartyMenu_PopPanelGroupAndRestoreSelection(self);
            WORD(0x1bb8) = 14;
            HALF(0x1bf6) = CountEligiblePartyEntriesAfterExclusions();
            WORD(0x1bc0) = 0;
        }
        return;
    }
    if (WORD(0x1bc0) == 1) {
        if (!_Z31IsSubBrightnessTransitionActiveP13GameResources(resources)) {
            GameState_EnableGlobalFlag64();
            ++WORD(0x1bc0);
        }
        return;
    }
    if (WORD(0x1bc0) == 2) {
        if (Menu_AdvanceSecondaryPanelResourceInitialization(self + 0x8b4)) {
            Graphics_LoadIndexedSubBG1Screen(self + 0x8b4, GameState_ReadProtagonistObjectIndex(state));
            Menu_DispatchSecondaryPanelCharacterView(self + 0x8b4, 0, GameState_ReadProtagonistObjectIndex(state));
            ++WORD(0x1bc0);
        }
        return;
    }
    if (WORD(0x1bc0) == 3) {
        _Z16SetSubBrightnessP13GameResourcesii(resources, 0, 15);
        ++WORD(0x1bc0);
        return;
    }
    if (WORD(0x1bc0) == 4) {
        if (PartyMenu_IsCancelRequested(self, 1) || Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]) {
            _Z16SetSubBrightnessP13GameResourcesii(resources, -16, 10);
            ++WORD(0x1bc0);
        }
        return;
    }
    if (WORD(0x1bc0) == 5) {
        if (!_Z31IsSubBrightnessTransitionActiveP13GameResources(resources)) {
            ComputeGrottoAndContextDependentStateFlags(0);
            RestoreSubGraphicsBanksAndDestroyAllocators(self + 0x8b4);
            BYTE(0x1cc3) = 0;
            ++WORD(0x1bc0);
        }
    }
}
