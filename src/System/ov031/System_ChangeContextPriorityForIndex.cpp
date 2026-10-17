#include <globaldefs.h>
ARM
extern "C" unsigned char data_02111304[];
extern "C" void _Z21ChangeContextPriorityP16ProcessorContextj(void *, unsigned int);
// Original: arm9/ov031 @ 0x02207D3C; symbol: func_ov031_02207d3c; size: 0x24.
extern "C" void System_ChangeContextPriorityForIndex(unsigned int index) {
    if (index < 0x20)
        _Z21ChangeContextPriorityP16ProcessorContextj(*(void **)(data_02111304 + 4), index);
}
