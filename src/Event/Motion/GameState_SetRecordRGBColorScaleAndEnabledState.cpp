#include <globaldefs.h>
ARM
extern "C" int _fflt(int);
// Original: arm9/ov001 @ 0x02159804; symbol: func_ov001_02159804; size: 0x1C.
extern "C" int GameState_SetRecordRGBColorScaleAndEnabledState(void *record, void *state) {
    *(int *)((char *)state + 0x8c) = _fflt(*(int *)((char *)record + 0x10));
    return 0;
}
