#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void Script_SetOpcodeHandlerTable(void *self, void **handlers, int count);
extern "C" void *data_ov023_021ffa4c[300];
struct HandlerEntry { void *handler; int opcode; };
extern "C" HandlerEntry data_ov023_021fddb8[];
// Original: arm9/ov023 @ 0x021EB000; symbol: func_ov023_021eb000; size: 0x80.
extern "C" void Script_InitializeOpcodeHandlers(void *self) {
    memset(data_ov023_021ffa4c, 0, 0x4b0);
    HandlerEntry *entry = data_ov023_021fddb8;
    while (entry) {
        void *handler = entry->handler;
        if (!handler) break;
        int opcode = entry->opcode;
        if (opcode >= 0 && opcode < 300) {
            if (data_ov023_021ffa4c[opcode]) { for (;;) {} }
            data_ov023_021ffa4c[opcode] = handler;
        }
        ++entry;
    }
    Script_SetOpcodeHandlerTable(self, data_ov023_021ffa4c, 300);
}
