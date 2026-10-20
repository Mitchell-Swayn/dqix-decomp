#include <globaldefs.h>
ARM
extern "C" unsigned int *Queue_AppendNode(void);
// Original: arm9/ov001 @ 0x02159044; symbol: func_ov001_02159044; size: 0x18.
extern "C" void Queue_AppendType6Node(void) {
    unsigned int *p = Queue_AppendNode();
    if (p) *p = 6;
}
