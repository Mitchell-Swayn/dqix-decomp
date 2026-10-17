#include <globaldefs.h>
ARM
extern "C" void Graphics_ReleaseBackgroundState(char *);
extern "C" void func_ov017_021b67d8(void *);
// Original: arm9/ov017 @ 0x021B6B8C; symbol: func_ov017_021b6b8c; size: 0x2C.
extern "C" void Graphics_ReleaseOptionalBackgroundStateAndMark(void *object) {
    char *background = *(char **)((unsigned char *)object + 0x24);
    if (background != 0)
        Graphics_ReleaseBackgroundState(background);
    func_ov017_021b67d8(object);
    ((unsigned char *)object)[1] = 1;
}
