#include <globaldefs.h>
ARM
extern "C" void Graphics_InitializeType13StateAndEnableObjectPlane(char *p);
extern "C" int World_HasBMDJInstanceForObject(void *object);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned int *p, unsigned int n);
// Original: arm9/ov017 @ 0x021991E4; symbol: func_ov017_021991e4; size: 0x48.
extern "C" void World_InitializeObjectIfHasBMDJInstance(unsigned char *base) {
    Graphics_InitializeType13StateAndEnableObjectPlane(*(char **)(base + 0x3720));
    *(unsigned int *)(*(unsigned char **)(base + 0x3720) + 0x0C) = *(unsigned int *)(base + 0x36BC);
    if (!World_HasBMDJInstanceForObject(*(void **)(base + 0x3720))) {
        return;
    }
    AppendLinkedNodeAndMarkActive(*(unsigned int **)(base + 0x36FC), (unsigned int)*(void **)(base + 0x3720));
}
