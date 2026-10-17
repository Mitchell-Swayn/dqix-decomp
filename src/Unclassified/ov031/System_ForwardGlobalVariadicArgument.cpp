#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224c698[];
extern "C" void ForwardVariadicArgumentsFromStack(void *a, unsigned b, unsigned c, ...);
// Original: arm9/ov031 @ 0x0223EA60; symbol: func_ov031_0223ea60; size: 0x24.
extern "C" void System_ForwardGlobalVariadicArgument(void *object) {
    ForwardVariadicArgumentsFromStack(object, 0x21, (unsigned)data_ov031_0224c698, 3, 1);
}
