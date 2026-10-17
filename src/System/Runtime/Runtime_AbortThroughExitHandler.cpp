#include <globaldefs.h>
extern "C" void Runtime_AbortProcess(void);
// Original: arm9/main @ 0x0200EFA0; symbol: func_0200efa0; size: 0xC.
extern "C" void Runtime_AbortThroughExitHandler(void) {
    ((void (*)(void))Runtime_AbortProcess)();
}
