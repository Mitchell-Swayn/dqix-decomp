#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
ARM
struct State;
extern "C" void Menu_SetCallbackTableAndCount(State*,unsigned,unsigned);
extern "C" void Menu_SetDisconnectCleanupCallback(State*,unsigned);
extern "C" int Grotto_RefreshStateAndClearResourceFlag();
struct SevenWordState { unsigned words[7]; };
// Original data: arm9/ov004 @ 0x2170154; symbol: data_ov004_02170154.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 00000000ecaa1602d0ac1602e8ac1602f0ac1602f8ac160220ad1602fcfffeff.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" SevenWordState GrottoAllocateSevenWordStateAndInstallRefreshCallback_UnknownRoleProcedureReferenceRecords;
// Original: arm9/ov004 @ 0x0216AE2C; symbol: func_ov004_0216ae2c; size: 0x70.
// Allocates a seven-word template copy and installs the grotto refresh callback in the context.
extern "C" void Grotto_AllocateSevenWordStateAndInstallRefreshCallback(SafeAllocator* allocator,State* context) {
 SevenWordState initial=GrottoAllocateSevenWordStateAndInstallRefreshCallback_UnknownRoleProcedureReferenceRecords;
 void* copy=allocator->Allocate(0x1c);
 memcpy(copy,&initial,0x1c);
 Menu_SetCallbackTableAndCount(context,(unsigned)copy,7);
 Menu_SetDisconnectCleanupCallback(context,(unsigned)Grotto_RefreshStateAndClearResourceFlag);
}
