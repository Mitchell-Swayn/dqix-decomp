#include "globaldefs.h"
#pragma optimize_for_size off
ARM
// Original data: arm9/main @ 0x20f1758; symbol: data_020f1758.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 14ce09020000000034ce09020100000078ce090202000000bcce09020300000000cf09020400000044cf09020500000088cf090206000000cccf090207000000 ...; full span in module reference.
// Observed span: 400 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109cc4; symbol: data_02109cc4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 196 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Pair{void*value;int index;};extern "C" void* memset(void*,int,unsigned);extern "C" void* ScriptRegisterFortyNineIndexedOpcodeHandlers_UnknownRoleZeroInitializedStorage[49];extern "C" Pair ScriptRegisterFortyNineIndexedOpcodeHandlers_UnknownRoleProcedureReferenceRecords[];extern "C" void Script_SetOpcodeHandlerTable(void*,void**,int);
// Original: arm9/main @ 0x0209DC4C; symbol: func_0209dc4c; size: 0x80.
extern "C" void Script_RegisterFortyNineIndexedOpcodeHandlers(void*p){memset(ScriptRegisterFortyNineIndexedOpcodeHandlers_UnknownRoleZeroInitializedStorage,0,196);Pair*pair=ScriptRegisterFortyNineIndexedOpcodeHandlers_UnknownRoleProcedureReferenceRecords;while(pair){void*value=pair->value;if(!value)break;int index=pair->index;if(index>=0&&index<49){if(ScriptRegisterFortyNineIndexedOpcodeHandlers_UnknownRoleZeroInitializedStorage[index]){for(;;){}}ScriptRegisterFortyNineIndexedOpcodeHandlers_UnknownRoleZeroInitializedStorage[index]=value;}++pair;}Script_SetOpcodeHandlerTable(p,ScriptRegisterFortyNineIndexedOpcodeHandlers_UnknownRoleZeroInitializedStorage,49);}
