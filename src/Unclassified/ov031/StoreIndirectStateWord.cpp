#include <globaldefs.h>
extern "C" {
extern int* data_ov031_0224e588;
}
// Original: arm9/ov031 @ 0x022103DC; symbol: func_ov031_022103dc; size: 0x1C.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM void StoreIndirectStateWord(int value)
{
    if(data_ov031_0224e588)
    {
        (void)*(volatile int*)data_ov031_0224e588;
        *data_ov031_0224e588=value;
    }
}
