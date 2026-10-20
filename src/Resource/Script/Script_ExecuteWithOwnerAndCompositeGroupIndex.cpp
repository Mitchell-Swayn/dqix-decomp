#include <globaldefs.h>
#include <Resource/Script.h>
struct Context {unsigned owner;short id;unsigned short arg;unsigned active;};
// Original data: arm9/main @ 0x20f16f8; symbol: data_020f16f8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 66000000d8be09020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109bc8; symbol: data_02109bc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern Context *ScriptApplyIdsWhenPackedDecimalRangeMatches_UnknownRoleZeroInitializedStorage;extern Script::OpcodeLookupEntry ScriptExecuteWithOwnerAndCompositeGroupIndex_UnknownRoleProcedureReferenceRecords[];}
// Original: arm9/main @ 0x0209C008; symbol: func_0209c008; size: 0x84.
extern "C" ARM void Script_ExecuteWithOwnerAndCompositeGroupIndex(unsigned owner,const void *code,unsigned size,unsigned short arg,int group,int index){ Script script;Context ctx;ctx.owner=owner;ctx.id=(short)(group*100+index);ctx.arg=arg;ctx.active=1;ScriptApplyIdsWhenPackedDecimalRangeMatches_UnknownRoleZeroInitializedStorage=&ctx;script.Initialize();script.SetOpcodeLookup(ScriptExecuteWithOwnerAndCompositeGroupIndex_UnknownRoleProcedureReferenceRecords);script.Load(code,size);script.Execute();}
