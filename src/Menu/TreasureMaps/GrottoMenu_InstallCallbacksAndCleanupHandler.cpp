#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
struct State;
extern "C" void Menu_SetCallbackTableAndCount(State *, unsigned, unsigned);
extern "C" void *memcpy(void *, const void *, unsigned);
extern "C" void Menu_SetDisconnectCleanupCallback(State *, unsigned);
extern "C" int GrottoMenu_ResetTextAndCommitMapCollection(void *);
struct TreasureMapCallbackTable { unsigned entries[38]; };
// Original data: arm9/ov004 @ 0x0216FF00; symbol: data_ov004_0216ff00.
// Thirty-eight callback-address words, including the null entry at index zero.
// Values and relocations: docs/data-symbols/ov004.md.
extern "C" const TreasureMapCallbackTable GrottoMenuInstallCallbacksAndCleanupHandler_UnknownRoleProcedureReferenceRecords;
#pragma force_active on
// Original: arm9/ov004 @ 0x02165DF4; symbol: func_ov004_02165df4; size: 0x7C.
// Copies the treasure-map callback table into the supplied arena and installs cleanup.
extern "C" void GrottoMenu_InstallCallbacksAndCleanupHandler(SafeAllocator *allocator, State *state)
{
    TreasureMapCallbackTable callbacks = GrottoMenuInstallCallbacksAndCleanupHandler_UnknownRoleProcedureReferenceRecords;
    void *table = allocator->Allocate(sizeof(callbacks));
    memcpy(table, &callbacks, sizeof(callbacks));
    Menu_SetCallbackTableAndCount(state, (unsigned)table, 38);
    Menu_SetDisconnectCleanupCallback(state, (unsigned)GrottoMenu_ResetTextAndCommitMapCollection);
}
