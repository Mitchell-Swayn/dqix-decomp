#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void Script_SetOpcodeHandlerTable(void *self, void **handlers, int count);
// Original data: arm9/ov023 @ 0x21ffa4c; symbol: data_ov023_021ffa4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1200 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" void *ScriptInitializeOpcodeHandlers_UnknownRoleZeroInitializedStorage[300];
struct HandlerEntry { void *handler; int opcode; };
// Original data: arm9/ov023 @ 0x21fddb8; symbol: data_ov023_021fddb8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 5c911e020000000090911e020100000008921e020200000044921e023200000078921e0233000000f0921e02340000004c931e023500000070931e0265000000 ...; full span in module reference.
// Observed span: 824 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" HandlerEntry ScriptInitializeOpcodeHandlers_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov023 @ 0x021EB000; symbol: func_ov023_021eb000; size: 0x80.
extern "C" void Script_InitializeOpcodeHandlers(void *self) {
    memset(ScriptInitializeOpcodeHandlers_UnknownRoleZeroInitializedStorage, 0, 0x4b0);
    HandlerEntry *entry = ScriptInitializeOpcodeHandlers_UnknownRoleProcedureReferenceRecords;
    while (entry) {
        void *handler = entry->handler;
        if (!handler) break;
        int opcode = entry->opcode;
        if (opcode >= 0 && opcode < 300) {
            if (ScriptInitializeOpcodeHandlers_UnknownRoleZeroInitializedStorage[opcode]) { for (;;) {} }
            ScriptInitializeOpcodeHandlers_UnknownRoleZeroInitializedStorage[opcode] = handler;
        }
        ++entry;
    }
    Script_SetOpcodeHandlerTable(self, ScriptInitializeOpcodeHandlers_UnknownRoleZeroInitializedStorage, 300);
}
