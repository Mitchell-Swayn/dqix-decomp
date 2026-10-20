#pragma opt_propagation off
#include <globaldefs.h>
ARM
#include <Resource/Script.h>
struct RecordScriptContext { void* volatile owner; void* volatile records; unsigned enabled; };
// Original data: arm9/main @ 0x2109bac; symbol: data_02109bac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" RecordScriptContext* MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20f1680; symbol: data_020f1680.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6400000030ad09026500000038ad09026600000040ad09026700000010ae0902680000009cae09020000000000000000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Script::OpcodeLookupEntry MonsterGroupScriptExecuteWithValidationContext_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0209AF58; symbol: func_0209af58; size: 0x7C.
// Runs a record-building script with a temporary owner/table context and the fixed opcode table.
// Volatile access views preserve the observed context writes, stack-argument read,
// and registry reload. The registry store remains ordinary for literal placement.
extern "C" void MonsterGroupScript_ExecuteWithValidationContext(void* owner, const void* code, unsigned length, unsigned unused, void* volatile records)
{
    Script script;
    RecordScriptContext contextStorage;
    if (code) {
        RecordScriptContext* context = &contextStorage;
        RecordScriptContext** contextSlot = &MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage;
        context->owner = owner;
        void* table = records;
        *contextSlot = context;
        context->records = table;
        (*(RecordScriptContext* volatile*)contextSlot)->enabled = 0;
        script.Initialize();
        script.SetOpcodeLookup(MonsterGroupScriptExecuteWithValidationContext_UnknownRoleProcedureReferenceRecords);
        script.Load(code, length);
        script.Execute();
    }
}
