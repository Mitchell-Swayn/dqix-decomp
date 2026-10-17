#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224e5e8[];
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(void *);
// Original: arm9/ov031 @ 0x02216A84; symbol: func_ov031_02216a84; size: 0x30.
extern "C" void AwaitProcessorContextIfFlagSet(void) {
    unsigned char *base = *(unsigned char **)(data_ov031_0224e5e8 + 8);
    if (*(unsigned int *)(base + 0x1384) != 0)
        _Z22AwaitContextCompletionP16ProcessorContext(base + 0x1318);
}
