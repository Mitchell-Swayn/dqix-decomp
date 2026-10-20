#include <globaldefs.h>
THUMB
// Original: arm9/ov031 @ 0x0221ECAC; symbol: System_ForwardSleepCurrentContextTicks; size: 0x8.
// Forwards the tick count to the established SleepCurrentContext routine.
extern "C" void _Z19SleepCurrentContextj(unsigned int);
extern "C" void System_ForwardSleepCurrentContextTicks(unsigned int ticks) {
    _Z19SleepCurrentContextj(ticks);
}
