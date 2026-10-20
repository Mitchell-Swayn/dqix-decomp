#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
ARM
struct State;
struct TableBlock {unsigned words[100];};
// Original data: arm9/ov004 @ 0x216fc40; symbol: data_ov004_0216fc40.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 00000000b87d150298821502a88315023c881502e8891502608a1502788b1502d48b1502cc8d1502ec8f15028493150268941502709415021c95150250961502 ...; full span in module reference.
// Observed span: 400 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" TableBlock ResourceInstallCopiedHundredWordTableAndSelectionCallback_UnknownRoleProcedureReferenceRecords;
extern "C" void Menu_SetCallbackTableAndCount(State*,unsigned,unsigned);
extern "C" void Menu_SetDisconnectCleanupCallback(State*,unsigned);
extern "C" int Menu_DeliverPendingPurchaseByItemKind(void*);
// Original: arm9/ov004 @ 0x0215E25C; symbol: func_ov004_0215e25c; size: 0x74.
// Copies a hundred-word table into allocator storage and installs its selection callback.
extern "C" void Resource_InstallCopiedHundredWordTableAndSelectionCallback(SafeAllocator* allocator,State* state) {
 TableBlock table=ResourceInstallCopiedHundredWordTableAndSelectionCallback_UnknownRoleProcedureReferenceRecords;
 void* storage=allocator->Allocate(sizeof(table));
 memcpy(storage,&table,sizeof(table));
 Menu_SetCallbackTableAndCount(state,(unsigned)storage,100);
 Menu_SetDisconnectCleanupCallback(state,(unsigned)Menu_DeliverPendingPurchaseByItemKind);
}
