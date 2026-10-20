#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215EFB8; symbol: func_ov003_0215efb8; size: 0x48.
extern "C" void InitializeBufferHeaderAndStatusBytes(void *p) {
    ((unsigned int *)p)[0] = 0; ((unsigned int *)p)[1] = 0; ((unsigned int *)p)[2] = 0; ((unsigned int *)p)[3] = 0; ((unsigned int *)p)[4] = 0; ((unsigned int *)p)[5] = 0; ((unsigned int *)p)[6] = 0;
    *(unsigned short *)((char *)p + 0x1c) = 0;
    unsigned char *b = (unsigned char *)p;
    b[0x1e] = 1;
    b[0x1f] = 0;
    b[0x20] = 0;
    b[0x21] = 1;
    b[0x22] = 0;
    b[0x23] = 1;
    b[0x24] = 1;
}
