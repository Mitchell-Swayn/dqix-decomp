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
struct ActionRecord {
    char unknown00[8];
    unsigned cost : 8, unknown8 : 2, targeting : 2, unknown12 : 20;
};
struct TargetResult { unsigned char first, pad; unsigned short middle; unsigned char last; };
struct SelectionAction {
    short action;
    signed char actor;
    unsigned char count;
    signed char targets[4];
    TargetResult firstRecords[4], secondRecords[4];
    unsigned flags;
};
struct ActionDispatcher { void* table; };
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" void* ActionData_GetGlobalTables();
extern "C" ActionRecord* ActionData_FindDefinitionInPrimaryOrSecondaryTable(void*, int);
extern "C" void* GameState_GetValidObjectByIndex(void*, int);
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void*);
extern "C" void __clear(void*, unsigned);
extern "C" int GameState_CopyActivePartySlotList(void*, unsigned char*);
extern "C" void PartyMenu_InitializeActionResults(SelectionAction*);
extern "C" void PartyMenu_ClearActionDispatcher(ActionDispatcher*);
extern "C" int PartyMenu_DispatchActionEffects(ActionDispatcher*, SelectionAction*, int);
// Link binding at shared address 0x0218B5C0: this call uses the ov017 snapshot ABI.
// The original ov002 relocation names the overlapping ov016 symbol.
extern "C" void Movie_NoOpOverlayHook(int, int);
extern "C" void Object_SubtractAmountWithConditionalScaling(void*, unsigned);
extern "C" void Network_QueueCurrentPartyMemberState(int, int, int, int);
// Original: arm9/ov002 @ 0x021594E8; symbol: func_ov002_021594e8; size: 0x28c.
// Executes an explicit-caster field action, chooses its feedback message, and deducts and synchronizes the successful action cost.
extern "C" void PartyMenu_ExecuteExplicitCasterAction(char* self, int action, int caster, int target)
{
    HALF(0x1c26) = action;
    char* state = _ZN9GameState11GetInstanceEv();
    void* tables = ActionData_GetGlobalTables();
    ActionRecord* definition = ActionData_FindDefinitionInPrimaryOrSecondaryTable(tables, HALF(0x1c26));
    void* object = GameState_GetValidObjectByIndex(state, caster);
    void* network = Network_GetConnectionManager();
    int spent = 0;
    if (WORD(0x1bb8) == 23) {
        HALF(0x1c28) = 0x232d;
        HALF(0x1c2a) = 0x232b;
        int success = 0;
        if (HALF(0x1c26) == 34) {
            SelectionAction request;
            PartyMenu_InitializeActionResults(&request);
            PartyMenu_InitializeActionResults(&request);
            ActionRecord* record = ActionData_FindDefinitionInPrimaryOrSecondaryTable(tables, HALF(0x1c26));
            if (record) {
                unsigned char slots[4];
                __clear(slots, 4);
                int count = GameState_CopyActivePartySlotList(state, slots);
                if (record->targeting & 1) {
                    request.action = HALF(0x1c26);
                    request.actor = caster;
                    request.count = count;
                    for (int i = 0; i < count; ++i) request.targets[i] = slots[i];
                    ActionDispatcher dispatcher;
                    PartyMenu_ClearActionDispatcher(&dispatcher);
                    dispatcher.table = tables;
                    success = PartyMenu_DispatchActionEffects(&dispatcher, &request, 0);
                }
            }
        } else {
            ActionRecord* record = ActionData_FindDefinitionInPrimaryOrSecondaryTable(tables, HALF(0x1c26));
            if (record && (record->targeting & 1)) {
                Movie_NoOpOverlayHook(0, -1);
                SelectionAction request;
                PartyMenu_InitializeActionResults(&request);
                PartyMenu_InitializeActionResults(&request);
                request.action = HALF(0x1c26);
                request.count = 1;
                request.targets[0] = target;
                request.actor = caster;
                ActionDispatcher dispatcher;
                PartyMenu_ClearActionDispatcher(&dispatcher);
                dispatcher.table = tables;
                success = PartyMenu_DispatchActionEffects(&dispatcher, &request, 0);
            }
        }
        if (success) {
            if (HALF(0x1c26) == 31 || HALF(0x1c26) == 30 || HALF(0x1c26) == 32 || HALF(0x1c26) == 33) {
                HALF(0x1c2a) = 0x2339;
                spent = 1;
            } else if (HALF(0x1c26) == 35) {
                HALF(0x1c2a) = 0x794c;
                spent = 1;
            } else if (HALF(0x1c26) == 34) {
                HALF(0x1c2a) = 0x2339;
                spent = 1;
            }
        }
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 100, 0);
        WORD(0x1bb8) = 38;
        WORD(0x1bbc) = 23;
    }
    if (spent) {
        Object_SubtractAmountWithConditionalScaling(object, definition->cost);
        if (Network_IsSessionActive(network)) Network_QueueCurrentPartyMemberState(caster, 0, 0, 1);
    }
}
