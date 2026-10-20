#include <globaldefs.h>
ARM
struct State;
struct Table { unsigned values[19]; };
// Original data: arm9/ov004 @ 0x21700ec; symbol: data_ov004_021700ec.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 00000000448b1602449116020c921602e89416020c951602589616026c981602f4981602289a1602dc9a16024c9b160264a41602e8a51602fca5160210a61602 ...; full span in module reference.
// Observed span: 76 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" Table ResourceInitializeTableWithCallback_UnknownRoleProcedureReferenceRecords;
extern "C" void Menu_RestoreDisplayAndRefreshWorldContext();
extern "C" void* memcpy(void*, const void*, unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Menu_SetCallbackTableAndCount(State*, unsigned, unsigned);
extern "C" void Menu_SetDisconnectCleanupCallback(State*, unsigned);
// Original: arm9/ov004 @ 0x0216AA70; symbol: func_ov004_0216aa70; size: 0x7C.
extern "C" void Resource_InitializeTableWithCallback(unsigned allocator, State* state) {
    Table table = ResourceInitializeTableWithCallback_UnknownRoleProcedureReferenceRecords;
    char* copy = _ZN13SafeAllocator8AllocateEj(allocator, sizeof(Table));
    memcpy(copy, &table, sizeof(Table));
    Menu_SetCallbackTableAndCount(state, (unsigned)copy, 19);
    Menu_SetDisconnectCleanupCallback(state, (unsigned)Menu_RestoreDisplayAndRefreshWorldContext);
}
