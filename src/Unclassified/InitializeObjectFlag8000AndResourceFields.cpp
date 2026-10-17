#include <globaldefs.h>
extern "C" {
void Object_InitializeAnimationControlDefaults(void);
// Original: arm9/main @ 0x020A75A0; symbol: func_020a75a0; size: 0x4C.
ARM void InitializeObjectFlag8000AndResourceFields(void *param_1) {
    unsigned char *p = (unsigned char *)param_1;
    Object_InitializeAnimationControlDefaults();
    *(unsigned short *)p |= 0x8000;
    *(unsigned int *)(p + 0x134) = 0;
    *(unsigned int *)(p + 0x138) = 0;
    *(unsigned short *)(p + 0x13c) = 0;
    *(unsigned int *)(p + 0x140) = 0;
    *(unsigned int *)(p + 0x150) = 0;
    *(unsigned int *)(p + 0x144) = 0;
    *(unsigned int *)(p + 0x148) = 0;
    *(unsigned int *)(p + 0x14c) = 0;
    p[0x15a] = 1;
}
}
