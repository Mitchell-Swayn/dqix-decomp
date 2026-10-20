#include <globaldefs.h>
ARM
extern "C" void WfcUtility_InsertListNodeBefore(unsigned value);
// Original: arm9/ov031 @ 0x0223D918; symbol: func_ov031_0223d918; size: 0x10.
extern "C" void WfcUtility_PrependListNode(void *object) {
    WfcUtility_InsertListNodeBefore(*(unsigned *)((char *)object + 4));
}
