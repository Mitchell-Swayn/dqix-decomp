#include <globaldefs.h>
ARM
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20f0b80; symbol: data_020f0b80.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 660000000812070200000000000000006600000044100702000000000000000066000000a4160702000000000000000064000000f40f070265000000fc0f0702 ...; full span in module reference.
// Observed span: 137 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108d70; symbol: data_02108d70.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State {unsigned short pad,a,b,c;unsigned unused,result;char pad2[8];int mode;char pad3[4];void* output;};extern "C" State ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage;extern "C" Script::OpcodeLookupEntry ScriptExecuteAndApplyModeDependentOutputCounts_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02071488; symbol: func_02071488; size: 0xEC.
extern "C" unsigned Script_ExecuteAndApplyModeDependentOutputCounts(void* code,unsigned size,int mode,char* out) {Script script;ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.output=out;ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.mode=mode;ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.result=0;ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.b=0;script.Initialize();script.SetOpcodeLookup(ScriptExecuteAndApplyModeDependentOutputCounts_UnknownRoleProcedureReferenceRecords);script.Load(code,size);script.Execute();out[7]=0;out[8]=0;if(mode>=21000 && mode<40000) {out[7]=1;short old=*(short*)(out+70);if(old>=0)*(short*)(out+70)=old+ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.a;}else if(mode>=40000) {out[8]=1;short old=*(short*)(out+70);if(old>=0)*(short*)(out+70)=old+ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.c;}return ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.result; }
