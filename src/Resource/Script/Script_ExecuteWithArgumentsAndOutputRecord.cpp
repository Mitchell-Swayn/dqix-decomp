#include <globaldefs.h>
#include <Resource/Script.h>
#pragma always_inline on
struct Output { unsigned value; unsigned short count; };
// Original data: arm9/main @ 0x20f1258; symbol: data_020f1258.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6400000074dc0802650000007cdc08026600000084dc08020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108fd4; symbol: data_02108fd4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Context { unsigned* count; void* arguments; Output* output; void* owner; inline void SetArguments(unsigned* c,void* a) {arguments=a;count=c;} }; extern Context ScriptExecuteWithArgumentsAndOutputRecord_UnknownRoleZeroInitializedStorage; extern Script::OpcodeLookupEntry ScriptExecuteWithArgumentsAndOutputRecord_UnknownRoleProcedureReferenceRecords[];
// The known overlay 13 caller supplies an argument-array pointer then a count
// in the fifth and sixth stack slots. The count address is consumed during Execute.
// Original: arm9/main @ 0x0208DF20; symbol: func_0208df20; size: 0x74.
extern "C" void Script_ExecuteWithArgumentsAndOutputRecord(Output* out,void* owner,const void* data,unsigned size,void* arguments,unsigned count) { void* args=arguments; out->value=0; out->count=0; ScriptExecuteWithArgumentsAndOutputRecord_UnknownRoleZeroInitializedStorage.owner=owner; ScriptExecuteWithArgumentsAndOutputRecord_UnknownRoleZeroInitializedStorage.SetArguments(&count,args); ScriptExecuteWithArgumentsAndOutputRecord_UnknownRoleZeroInitializedStorage.output=out; Script script; script.Initialize(); script.SetOpcodeLookup(ScriptExecuteWithArgumentsAndOutputRecord_UnknownRoleProcedureReferenceRecords); script.Load(data,size); script.Execute(); }
