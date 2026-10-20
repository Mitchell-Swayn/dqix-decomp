#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021D4CC0; symbol: func_ov017_021d4cc0; size: 0xC.
extern "C" void Script_SetOpcodeHandlerTable(void *self, void **handlers, int count) {
    *(void ***)((char *)self + 8) = handlers;
    *(int *)((char *)self + 4) = count;
}
