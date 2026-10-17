#include <globaldefs.h>
ARM
struct CounterState { char padding[0x44]; unsigned long long counter; };
extern "C" CounterState data_ov016_0219d144;
// Original: arm9/ov016 @ 0x0218CF34; symbol: func_ov016_0218cf34; size: 0x24.
extern "C" void Util_IncrementGlobal64BitCounterAt44(void) {
    ++data_ov016_0219d144.counter;
}
