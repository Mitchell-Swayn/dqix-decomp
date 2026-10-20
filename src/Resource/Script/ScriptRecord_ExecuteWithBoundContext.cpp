#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20f2308; symbol: data_020f2308.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 640000003c770d026500000044770d02660000004c770d026700000054770d020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x214e33c; symbol: data_0214e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State{short x,pad;void* a;unsigned b;void* c;};extern "C" State LoadFileIntoMemory_UnknownRoleZeroInitializedStorage;extern "C" Script::OpcodeLookupEntry ScriptRecordExecuteWithBoundContext_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020D7870; symbol: func_020d7870; size: 0x70.
extern "C" void ScriptRecord_ExecuteWithBoundContext(unsigned char* p,unsigned b,const void* code,unsigned size,bool existing){LoadFileIntoMemory_UnknownRoleZeroInitializedStorage.c=p;LoadFileIntoMemory_UnknownRoleZeroInitializedStorage.b=b;if(!existing){LoadFileIntoMemory_UnknownRoleZeroInitializedStorage.a=p+4;LoadFileIntoMemory_UnknownRoleZeroInitializedStorage.x=*(short*)(p+20);}Script s;s.Initialize();s.SetOpcodeLookup(ScriptRecordExecuteWithBoundContext_UnknownRoleProcedureReferenceRecords);s.Load(code,size);s.Execute();}
