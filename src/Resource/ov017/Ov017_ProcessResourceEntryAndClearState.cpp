#include <globaldefs.h>
ARM
extern "C" unsigned char *GameResources_GetInstance(void);
extern "C" void func_ov017_021a3b40(void *resource, int value);
extern "C" void func_0205c96c(void *object, unsigned value);
// Original: arm9/ov017 @ 0x021AFA70; symbol: func_ov017_021afa70; size: 0x2C.
extern "C" void Ov017_ProcessResourceEntryAndClearState(unsigned char *self) {
    unsigned char *resources = GameResources_GetInstance() + 0x3000;
    func_ov017_021a3b40(*(void **)(resources + 0x700), *(int *)(self + 4));
    func_0205c96c(self + 0x48, 0);
}
