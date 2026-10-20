#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021BD398; symbol: func_ov017_021bd398; size: 0xC.
extern "C" void FieldEvent_MarkScriptDispatchRequested(void *object) {
    *(unsigned char *)((char *)object + 0x108) = 1;
}
