#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(int value);

// Combat script opcode procedure (Script::OpcodeProc table in data_ov000_02183b5c).
// Original: arm9/ov000 @ 0x0216A350; symbol: func_ov000_0216a350; size: 0x14.
extern "C" int func_ov000_0216a350(void* parameters, int argumentCount)
{
    Combat_AllocateAndRegisterOwnerEntry(0xb);
    return 1;
}
