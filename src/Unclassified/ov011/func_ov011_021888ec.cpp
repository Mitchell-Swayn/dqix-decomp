#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov011_021889a0[];
extern "C" void Script_SetOpcodeHandlerTable(void *, void *, int);
// Original: arm9/ov011 @ 0x021888EC; symbol: func_ov011_021888ec; size: 0x18.
extern "C" void func_ov011_021888ec(void *p) {
    Script_SetOpcodeHandlerTable(p, data_ov011_021889a0, 0x73);
}
