#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
ARM
struct State;
extern "C" void Menu_SetCallbackTableAndCount(State*,unsigned,unsigned);
struct Words10 {unsigned words[10];};
// Original data: arm9/ov004 @ 0x2170264; symbol: data_ov004_02170264.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 0000000074ea1602d0ec16029ced1602b0f31602fcf4160220f6160234f6160288f7160224f81602.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" Words10 AllocateAndInstallTenWordTable_UnknownRoleProcedureReferenceRecords;
// Original: arm9/ov004 @ 0x0216F854; symbol: func_ov004_0216f854; size: 0x6C.
// Allocates a copied ten-word table and installs its address and count in the state.
// The owner API represents the installed address as unsigned; its State layout remains external.
extern "C" void AllocateAndInstallTenWordTable(SafeAllocator* allocator,State* state){
 Words10 table=AllocateAndInstallTenWordTable_UnknownRoleProcedureReferenceRecords;
 void* buffer=allocator->Allocate(40);
 memcpy(buffer,&table,40);
 Menu_SetCallbackTableAndCount(state,(unsigned)buffer,10);
}
