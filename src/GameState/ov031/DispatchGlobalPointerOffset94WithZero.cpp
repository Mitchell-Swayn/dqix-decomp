#include <globaldefs.h>
ARM
extern "C" void *data_ov031_02290d00;
extern "C" void DispatchValueThroughFirstPointer(void **, int);
// Original: arm9/ov031 @ 0x022368E0; symbol: func_ov031_022368e0; size: 0x20.
extern "C" void DispatchGlobalPointerOffset94WithZero(void) {
    DispatchValueThroughFirstPointer((void **)((char *)data_ov031_02290d00 + 0x94), 0);
}
