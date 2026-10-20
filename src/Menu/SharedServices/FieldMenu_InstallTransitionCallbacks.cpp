#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
struct State;
extern "C" void Menu_SetCallbackTableAndCount(State *, unsigned, unsigned);
extern "C" void *memcpy(void *, const void *, unsigned);
struct FieldTransitionCallbackTable { unsigned entries[5]; };
// Original data: arm9/ov004 @ 0x021700C0; symbol: data_ov004_021700c0.
// Five callback-address words: null followed by four field-transition callbacks.
// Values and relocations: docs/data-symbols/ov004.md.
extern "C" const FieldTransitionCallbackTable FieldMenuInstallTransitionCallbacks_UnknownRoleProcedureReferenceRecords;
#pragma force_active on
// Original: arm9/ov004 @ 0x021689D8; symbol: func_ov004_021689d8; size: 0x60.
// Copies the field-transition callbacks into the supplied arena and installs the table.
extern "C" void FieldMenu_InstallTransitionCallbacks(SafeAllocator *allocator, State *state)
{
    FieldTransitionCallbackTable callbacks = FieldMenuInstallTransitionCallbacks_UnknownRoleProcedureReferenceRecords;
    void *table = allocator->Allocate(sizeof(callbacks));
    memcpy(table, &callbacks, sizeof(callbacks));
    Menu_SetCallbackTableAndCount(state, (unsigned)table, 5);
}
