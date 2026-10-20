#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021BB9FC; symbol: func_ov017_021bb9fc; size: 0xC.
extern "C" short FieldEvent_GetRemoteEventToken(void *object) {
    return *(short *)((char *)object + 0x14e);
}
