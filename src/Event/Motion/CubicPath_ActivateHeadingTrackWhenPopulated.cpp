#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x02157ACC; symbol: func_ov001_02157acc; size: 0x14.
extern "C" void CubicPath_ActivateHeadingTrackWhenPopulated(void *p) {
    if (*(int *)((char *)p + 0xc4) > 0)
        *(int *)((char *)p + 0x464) = 1;
}
