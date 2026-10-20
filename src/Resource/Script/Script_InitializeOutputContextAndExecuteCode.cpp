#include <globaldefs.h>
ARM
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20f0994; symbol: data_020f0994.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 0300000010c0060204000000f8c0060205000000c0c2060206000000e8c406020700000014c6060208000000f4c60602090000002cc806020a00000038c90602 ...; full span in module reference.
// Observed span: 168 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct ScriptState {unsigned char a,b,c,pad;short d,e,f,g;unsigned short h,padE;unsigned* out;unsigned value;};extern "C" ScriptState ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage;extern "C" Script::OpcodeLookupEntry ScriptInitializeOutputContextAndExecuteCode_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0206DA80; symbol: func_0206da80; size: 0xA0.
extern "C" int Script_InitializeOutputContextAndExecuteCode(unsigned* out,unsigned a,unsigned b,unsigned c,unsigned d,unsigned value,const void* code,unsigned length){Script script;if(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.out){*out=0;ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.g=0;ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.f= -1;ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.d= -1;ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.e= -1;}*out=0;ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.c=a;ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.b=b;ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.a=c;ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.h=d;ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.out=out;ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.value=value;script.Initialize();script.SetOpcodeLookup(ScriptInitializeOutputContextAndExecuteCode_UnknownRoleProcedureReferenceRecords);script.Load(code,length);script.Execute();return 1;}
