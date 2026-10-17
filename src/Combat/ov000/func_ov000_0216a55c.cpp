#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(int value);

// Combat script opcode procedure (func_ov000_0216a55c::OpcodeProc table in data_ov000_02183b5c).
// Original: arm9/ov000 @ 0x0216A55C; symbol: func_ov000_0216a55c; size: 0x14.
extern "C" int func_ov000_0216a55c(void* parameters, int argumentCount)
{
    Combat_AllocateAndRegisterOwnerEntry(0x13);
    return 1;
}
