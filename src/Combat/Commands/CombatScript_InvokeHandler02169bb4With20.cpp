#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(int value);

// Combat script opcode procedure (Script::OpcodeProc table in data_ov000_02183b5c).
// Original: arm9/ov000 @ 0x0216AC7C; symbol: func_ov000_0216ac7c; size: 0x14.
extern "C" int CombatScript_InvokeHandler02169bb4With20(void* parameters, int argumentCount)
{
    Combat_AllocateAndRegisterOwnerEntry(0x20);
    return 1;
}
