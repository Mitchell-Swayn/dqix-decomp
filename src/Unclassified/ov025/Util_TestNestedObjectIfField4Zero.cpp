#include <globaldefs.h>
ARM
extern "C" int GameState_AreRecordFields150And15EClear(void *object);
// Original: arm9/ov025 @ 0x021E9528; symbol: func_ov025_021e9528; size: 0x30.
extern "C" int Util_TestNestedObjectIfField4Zero(void *object) {
    if (*(int *)((char *)object + 4))
        return 0;
    return GameState_AreRecordFields150And15EClear((char *)object + 0x5e8) != 0;
}
