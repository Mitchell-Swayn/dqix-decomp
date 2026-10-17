#include <globaldefs.h>
ARM
// Combat script opcode procedure that ignores its arguments and reports success.
// Original: arm9/ov000 @ 0x0216A428; symbol: func_ov000_0216a428; size: 0x8.
extern "C" int CombatScript_IgnoreOpcodeAndReturnTrue(void* parameters, int argumentCount)
{
    return 1;
}
