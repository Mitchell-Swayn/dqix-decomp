#include <globaldefs.h>
ARM
extern "C" char *data_ov031_02290d24;
extern "C" void _Z40NitroVM_Command_AcquireCardReadResourcest(unsigned short);
extern "C" void _Z40NitroVM_Command_ReleaseCardReadResourcest(unsigned short);
// Original: arm9/ov031 @ 0x0223B560; symbol: func_ov031_0223b560; size: 0x64.
extern "C" int Overlay_HandleCardReadCommand(void *unused, int command) {
    switch (command) {
    case 9:
        _Z40NitroVM_Command_AcquireCardReadResourcest(*(unsigned short *)(data_ov031_02290d24 + 0xe4));
        return 0;
    case 10:
        _Z40NitroVM_Command_ReleaseCardReadResourcest(*(unsigned short *)(data_ov031_02290d24 + 0xe4));
        return 0;
    case 1: return 4;
    default: return 8;
    }
}
