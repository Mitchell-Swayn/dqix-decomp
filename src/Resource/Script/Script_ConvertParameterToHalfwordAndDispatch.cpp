#pragma thumb off
#pragma optimization_level 3
#pragma optimize_for_size on
#pragma optimize_for_size off
namespace Script { class Parameter { public:int ToInt() const; }; }
// Original data: arm9/main @ 0x2108da8; symbol: data_02108da8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void ScriptValueTable_AllocateRecords(void*,void*,unsigned);extern void* ScriptConvertParameterToHalfwordAndDispatch_UnknownRoleZeroInitializedStorage[2];}
// Original: arm9/main @ 0x0207236C; symbol: func_0207236c; size: 0x2C.
extern "C" int Script_ConvertParameterToHalfwordAndDispatch(const Script::Parameter* value){int count=value->ToInt();count&=0xffff;ScriptValueTable_AllocateRecords(ScriptConvertParameterToHalfwordAndDispatch_UnknownRoleZeroInitializedStorage[1],ScriptConvertParameterToHalfwordAndDispatch_UnknownRoleZeroInitializedStorage[0],count);return 1;}
