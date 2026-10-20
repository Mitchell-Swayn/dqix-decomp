#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(int value);

// Combat script opcode procedure (Script::OpcodeProc table in data_ov000_02183b5c).
// Original: arm9/ov000 @ 0x0216A948; symbol: func_ov000_0216a948; size: 0x14.
extern "C" int Combat_AllocateAndRegisterOwnerEntryForOpcode24(void* parameters, int argumentCount)
{
    Combat_AllocateAndRegisterOwnerEntry(0x18);
    return 1;
}
