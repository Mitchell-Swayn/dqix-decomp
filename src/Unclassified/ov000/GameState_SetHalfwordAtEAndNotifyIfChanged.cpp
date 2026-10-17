#include <globaldefs.h>
ARM
extern "C" void OV000_ApplyTransformWhenObjectFlagged(void *object);
// Original: arm9/ov000 @ 0x02176150; symbol: func_ov000_02176150; size: 0x1C.
extern "C" void GameState_SetHalfwordAtEAndNotifyIfChanged(void *object, short value) {
    if (value == *(signed short *)((char *)object + 0xe))
        return;
    *(unsigned short *)((char *)object + 0xe) = value;
    OV000_ApplyTransformWhenObjectFlagged(object);
}
