#include <globaldefs.h>
#pragma optimization_level 1
ARM
extern "C" int IPC_QueryCommandFifteenValueSix(unsigned int *out);
extern "C" unsigned int SendOperation18WithHalfwordValue(unsigned int value);
// Original: arm9/ov031 @ 0x0223DFD0; symbol: func_ov031_0223dfd0; size: 0x2C.
extern "C" void System_SendOperation18IfCommandValueIsNot15(void) {
    unsigned int value;
    if (IPC_QueryCommandFifteenValueSix(&value) != 0)
        goto done;
    if (value == 0x0f)
        goto done;
    SendOperation18WithHalfwordValue(0x0f);
done:
    return;
}
