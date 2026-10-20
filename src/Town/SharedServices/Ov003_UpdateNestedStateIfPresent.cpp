#include <globaldefs.h>
ARM
extern "C" void Graphics_UpdateStageResourceRecords(void *state);
// Original: arm9/ov003 @ 0x0217EEC4; symbol: func_ov003_0217eec4; size: 0x18.
extern "C" void Ov003_UpdateNestedStateIfPresent(void *object) {
    void *state = *(void **)((char *)object + 0x1c);
    if (state)
        Graphics_UpdateStageResourceRecords(state);
}
