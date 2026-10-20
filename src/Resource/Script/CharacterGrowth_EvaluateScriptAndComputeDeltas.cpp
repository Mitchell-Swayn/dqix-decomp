#include "globaldefs.h"
#pragma optimize_for_size on
ARM
#include "Resource/Script.h"
// Original data: arm9/main @ 0x20f0ff8; symbol: data_020f0ff8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 660000006420080267000000102408020000000000000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108ee8; symbol: data_02108ee8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Packed{unsigned a:10,b:10,c:10,unused:2;};struct Metrics{unsigned scalar:32;unsigned short a:7,b:9;unsigned short pad;Packed x,y,z;};struct Output{Metrics start,end,delta;unsigned char pad[24];};struct Context{int success,a,b;Output*out;int reserved;};extern "C" Context CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage;extern "C" Script::OpcodeLookupEntry ScriptExecuteCodeIntoClearedOutputRecord_UnknownRoleProcedureReferenceRecords[];extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x02082490; symbol: func_02082490; size: 0x2BC.
extern "C" unsigned short CharacterGrowth_EvaluateScriptAndComputeDeltas(Output*out,const void*code,unsigned length,int a,int b){Script script;memset(out,0,84);CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage.reserved=0;CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage.out=out;CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage.a=b;CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage.b=a;CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage.success=0;script.Initialize();script.SetOpcodeLookup(ScriptExecuteCodeIntoClearedOutputRecord_UnknownRoleProcedureReferenceRecords);script.Load(code,length);script.Execute();unsigned short result;if(CharacterGrowthRecordScriptBreakpoint_UnknownRoleZeroInitializedStorage.success){out->delta.a=out->end.a-out->start.a;out->delta.scalar=out->end.scalar-out->start.scalar;out->delta.x.a=out->end.x.a-out->start.x.a;out->delta.x.c=out->end.x.c-out->start.x.c;out->delta.x.b=out->end.x.b-out->start.x.b;out->delta.y.a=out->end.y.a-out->start.y.a;out->delta.y.b=out->end.y.b-out->start.y.b;out->delta.z.a=out->end.z.a-out->start.z.a;out->delta.y.c=out->end.y.c-out->start.y.c;out->delta.z.b=out->end.z.b-out->start.z.b;out->delta.z.c=out->end.z.c-out->start.z.c;out->delta.b=out->end.b-out->start.b;result=out->end.a;}else result=0;return result;}
