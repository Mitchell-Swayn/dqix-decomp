#include <globaldefs.h>
ARM
extern "C" void Graphics_ResetSharedSceneState(void);
extern "C" void func_ov017_021bb27c(void *);
// Original: arm9/ov001 @ 0x02156534; symbol: func_ov001_02156534; size: 0x24.
extern "C" unsigned int Graphics_InitializeObjectAndReturnHalfword(void *object) {
    Graphics_ResetSharedSceneState();
    func_ov017_021bb27c(object);
    ((unsigned char *)object)[1] = 1;
    return *(unsigned short *)((unsigned char *)object + 0x0a);
}
