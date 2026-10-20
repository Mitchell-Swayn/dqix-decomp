#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Entry { void* value; int index; };
// Original data: arm9/ov001 @ 0x2165d74; symbol: data_ov001_02165d74.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" void* EventInitializeScriptOpcodeHandlerTable_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x2164d6c; symbol: data_ov001_02164d6c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 1cae15020000000084ae150201000000b8ae150202000000f0ae15020300000034af15020400000060af1502050000008caf150206000000ecaf150207000000 ...; full span in module reference.
// Observed span: 2440 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" Entry EventInitializeScriptOpcodeHandlerTable_UnknownRoleProcedureReferenceRecords[];
extern "C" void Script_SetOpcodeHandlerTable(void*,void**,int);
// Original: arm9/ov001 @ 0x02164114; symbol: func_ov001_02164114; size: 0x80.
extern "C" void Event_InitializeScriptOpcodeHandlerTable(void* self) {
 memset(EventInitializeScriptOpcodeHandlerTable_UnknownRoleZeroInitializedStorage,0,4000);
 Entry* p=EventInitializeScriptOpcodeHandlerTable_UnknownRoleProcedureReferenceRecords;
 while(p) {
  void* value=p->value;
  if(!value) break;
  int index=p->index;
  if(index>=0 && index<1000) {
   if(EventInitializeScriptOpcodeHandlerTable_UnknownRoleZeroInitializedStorage[index]) { for(;;) {} }
   EventInitializeScriptOpcodeHandlerTable_UnknownRoleZeroInitializedStorage[index]=value;
  }
  p++;
 }
 Script_SetOpcodeHandlerTable(self,EventInitializeScriptOpcodeHandlerTable_UnknownRoleZeroInitializedStorage,1000);
}
