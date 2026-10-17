#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(int value);

// Combat script opcode procedure (Script::OpcodeProc table in data_ov000_02183b5c).
// Original: arm9/ov000 @ 0x0216AC68; symbol: func_ov000_0216ac68; size: 0x14.
extern "C" int CombatScript_InvokeHandler02169bb4With1F(void* parameters, int argumentCount)
{
    Combat_AllocateAndRegisterOwnerEntry(0x1F);
    return 1;
}
