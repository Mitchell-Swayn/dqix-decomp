#pragma opt_propagation off
#include <globaldefs.h>
ARM
#include <Resource/Script.h>
struct RecordScriptContext { void* volatile owner; void* volatile records; unsigned enabled; };
extern "C" RecordScriptContext* data_02109bac;
extern "C" Script::OpcodeLookupEntry data_020f1680[];
// Original: arm9/main @ 0x0209AF58; symbol: func_0209af58; size: 0x7C.
// Runs a record-building script with a temporary owner/table context and the fixed opcode table.
// Volatile access views preserve the observed context writes, stack-argument read,
// and registry reload. The registry store remains ordinary for literal placement.
extern "C" void Script_RunRecordBuilderWithContext(void* owner, const void* code, unsigned length, unsigned unused, void* volatile records)
{
    Script script;
    RecordScriptContext contextStorage;
    if (code) {
        RecordScriptContext* context = &contextStorage;
        RecordScriptContext** contextSlot = &data_02109bac;
        context->owner = owner;
        void* table = records;
        *contextSlot = context;
        context->records = table;
        (*(RecordScriptContext* volatile*)contextSlot)->enabled = 0;
        script.Initialize();
        script.SetOpcodeLookup(data_020f1680);
        script.Load(code, length);
        script.Execute();
    }
}
