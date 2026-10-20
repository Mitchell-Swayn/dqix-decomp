#include <globaldefs.h>
ARM
extern "C" int Combat_TestMonsterDescriptorMode(void *, int, int, int);
// Original: arm9/ov024 @ 0x021D901C; symbol: func_ov024_021d901c; size: 0x44.
extern "C" int Math_ScaleValueIfIndexedObjectModeMatches(void *objectRef, int ignored, int index, int ignored3, int ignored4, int value) {
    if (Combat_TestMonsterDescriptorMode(*(void **)objectRef, (short)index, 6, 0) == 0) return value;
    return (int)((float)value * 1.5f);
}
