#include <globaldefs.h>
ARM

struct ProcessorContext;
extern "C" int _Z17IsContextInactiveP16ProcessorContext(ProcessorContext *context);
extern "C" void System_MarkStateReadyAndAwaitContext(void *state);
extern "C" unsigned char data_ov031_0224e69c[];

// Original: arm9/ov031 @ 0x0221A854; symbol: func_ov031_0221a854; size: 0x48.
extern "C" void System_UpdateContextWhenActive(void) {
    if (*(unsigned char **)(data_ov031_0224e69c) == 0) return;
    if (*(void **)(*(unsigned char **)(data_ov031_0224e69c) + 0x1bac) == 0) return;
    if (_Z17IsContextInactiveP16ProcessorContext((ProcessorContext *)(*(unsigned char **)(data_ov031_0224e69c) + 0x1b40)) != 0) return;
    System_MarkStateReadyAndAwaitContext(*(unsigned char **)(data_ov031_0224e69c) + 8);
}
